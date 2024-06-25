from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from .models import TemperatureReading
from .serializers import TemperatureReadingSerializer
from django.utils import timezone

class RegisterSensorView(APIView):
    def post(self, request, *args, **kwargs):
        sensor_id = request.data.get('sensor_id')
        if sensor_id:
            if not TemperatureReading.objects.filter(sensor_id=sensor_id).exists():
                TemperatureReading.objects.create(sensor_id=sensor_id, temperature=0.0, timestamp=timezone.now())
                return Response({"message": "Sensor registered successfully."}, status=status.HTTP_201_CREATED)
            return Response({"message": "Sensor already exists."}, status=status.HTTP_400_BAD_REQUEST)
        return Response({"message": "Sensor ID is required."}, status=status.HTTP_400_BAD_REQUEST)

class UpdateTemperatureView(APIView):
    def post(self, request, *args, **kwargs):
        serializer = TemperatureReadingSerializer(data=request.data)
        if serializer.is_valid():
            sensor_id = serializer.validated_data['sensor_id']
            temperature = serializer.validated_data['temperature']
            try:
                sensor = TemperatureReading.objects.get(sensor_id=sensor_id)
                sensor.temperature = temperature
                sensor.timestamp = timezone.now()  # Обновляем временную метку
                sensor.save()
                return Response(serializer.data, status=status.HTTP_200_OK)
            except TemperatureReading.DoesNotExist:
                return Response({"message": "Sensor not found."}, status=status.HTTP_404_NOT_FOUND)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class GetTemperatureView(APIView):
    def get(self, request, sensor_id, *args, **kwargs):
        try:
            sensor = TemperatureReading.objects.get(sensor_id=sensor_id)
            serializer = TemperatureReadingSerializer(sensor)
            return Response(serializer.data, status=status.HTTP_200_OK)
        except TemperatureReading.DoesNotExist:
            return Response({"message": "Sensor not found."}, status=status.HTTP_404_NOT_FOUND)

def index(request):
    readings = TemperatureReading.objects.all().order_by('-timestamp')
    return render(request, 'temperature/index.html', {'readings': readings})

def about(request):
    return render(request, 'temperature/about.html')
