from django.db import models

class TemperatureReading(models.Model):
    sensor_id = models.CharField(max_length=50)
    temperature = models.FloatField()
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"Sensor {self.sensor_id}: {self.temperature}°C at {self.timestamp}"
