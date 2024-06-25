from django.urls import path
from .views import RegisterSensorView, UpdateTemperatureView, GetTemperatureView, index, about

urlpatterns = [
    path('register/', RegisterSensorView.as_view(), name='register_sensor'),
    path('update/', UpdateTemperatureView.as_view(), name='update_temperature'),
    path('temperature/<str:sensor_id>/', GetTemperatureView.as_view(), name='get_temperature'),
    path('index/', index, name='index'),
    path('about/', about, name='about'),
]
