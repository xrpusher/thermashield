from django.contrib import admin
from .models import TemperatureReading

class TemperatureReadingAdmin(admin.ModelAdmin):
    list_display = ('sensor_id', 'temperature', 'timestamp')
    search_fields = ('sensor_id',)
    list_filter = ('timestamp',)

admin.site.register(TemperatureReading, TemperatureReadingAdmin)
