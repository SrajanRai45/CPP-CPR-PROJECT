# 💪 AllData Client — CPR-powered C++ Interface for FastAPI Fitness App

Welcome to **AllData Client**, a blazing-fast **C++ application** built using the **CPR** library that connects seamlessly to a Python-based **FastAPI fitness server** hosted right on your GitHub! This client empowers developers to interact with health and workout data using a variety of powerful commands.

---

## ⚙️ Features

This application allows communication with a **FastAPI backend** through simple command-line options. The backend is already available on your GitHub, so contributors can easily clone and set up both ends!

### ✅ Supported Commands:

| Command        | Description                                           |
|----------------|-------------------------------------------------------|
| `alldata`      | Fetches **all fitness entries** from the server.     |
| `get entry`    | Retrieves a **specific entry** by its ID.            |
| `add entry`    | Adds a **new fitness record** to the server.         |
| `delete entry` | Deletes an entry based on its ID.                    |
| `update entry` | Updates an existing record with new information.     |

Each of these commands connects to your Python **FastAPI** server and returns the appropriate response, enabling developers to create, view, modify, or delete workout-related data effortlessly!

---

## 🧱 Project Structure

After building the project with **CMake**, your binaries and executables will be available in:

