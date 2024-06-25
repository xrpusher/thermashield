import tkinter as tk
from tkinter import messagebox
import requests

def register_sensor():
    server_url = server_entry.get()
    sensor_id = sensor_entry.get()
    if not server_url or not sensor_id:
        messagebox.showwarning("Input Error", "Server URL and Sensor ID are required.")
        return

    url = f"{server_url}/api/register/"
    data = {"sensor_id": sensor_id}
    try:
        response = requests.post(url, json=data)
        if response.status_code == 201:
            messagebox.showinfo("Success", "Sensor registered successfully.")
        elif response.status_code == 400:
            messagebox.showwarning("Error", "Sensor already exists.")
        else:
            messagebox.showerror("Error", f"Failed to register sensor. Status code: {response.status_code}")
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

def update_temperature():
    server_url = server_entry.get()
    sensor_id = sensor_entry.get()
    temperature = temperature_entry.get()
    if not server_url or not sensor_id or not temperature:
        messagebox.showwarning("Input Error", "Server URL, Sensor ID, and Temperature are required.")
        return

    url = f"{server_url}/api/update/"
    data = {"sensor_id": sensor_id, "temperature": float(temperature)}
    try:
        response = requests.post(url, json=data)
        if response.status_code == 200:
            messagebox.showinfo("Success", "Temperature updated successfully.")
        elif response.status_code == 404:
            messagebox.showwarning("Error", "Sensor not found.")
        else:
            messagebox.showerror("Error", f"Failed to update temperature. Status code: {response.status_code}")
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

# Создание главного окна
root = tk.Tk()
root.title("Temperature Sensor Manager")

# URL сервера
tk.Label(root, text="Server URL:").grid(row=0, column=0, padx=10, pady=10)
server_entry = tk.Entry(root, width=50)
server_entry.grid(row=0, column=1, padx=10, pady=10)
server_entry.insert(0, "http://127.0.0.1:8000")

# ID датчика
tk.Label(root, text="Sensor ID:").grid(row=1, column=0, padx=10, pady=10)
sensor_entry = tk.Entry(root, width=50)
sensor_entry.grid(row=1, column=1, padx=10, pady=10)

# Температура
tk.Label(root, text="Temperature:").grid(row=2, column=0, padx=10, pady=10)
temperature_entry = tk.Entry(root, width=50)
temperature_entry.grid(row=2, column=1, padx=10, pady=10)

# Кнопка регистрации датчика
register_button = tk.Button(root, text="Register Sensor", command=register_sensor)
register_button.grid(row=3, column=0, columnspan=2, pady=10)

# Кнопка обновления температуры
update_button = tk.Button(root, text="Update Temperature", command=update_temperature)
update_button.grid(row=4, column=0, columnspan=2, pady=10)

# Запуск главного цикла
root.mainloop()
