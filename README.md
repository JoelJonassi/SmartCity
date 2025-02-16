# Smart City Project  

## Overview  

As urban mobility evolves, new short-distance transportation solutions, particularly electric vehicles like scooters and bicycles, are becoming increasingly popular. This project aims to develop a **digital management system** for urban mobility in a **smart-city context**, ensuring efficient **registration, sharing, and usage** of electric mobility devices.  

The proposed system follows the **imperative programming paradigm** and is implemented in **C**. Users will pick up and return electric mobility devices at the same location, making management more streamlined and structured.  

## Features  

### Data Handling  

- **Load & Validate Requests**  
  Reads a text file containing **user requests** for electric mobility, including request ID, user NIF (tax identification number), mobility code, usage time (minutes), and distance (km). The system ensures that the selected mobility device has enough autonomy to complete the requested distance.  

  **Example Request File:**  

  | Request No. | NIF       | Code | Time (min) | Distance (km) |
  |------------|----------|------|------------|--------------|
  | 1          | 12345678 | M_1  | 75         | 3            |
  | 2          | 11223344 | M_2  | 100        | 2            |
  | 3          | 10203040 | M_4  | 50         | 2            |

- **Load & Validate Mobility Devices**  
  Reads a text file containing **electric mobility devices** with their **ID, type, cost per minute, and autonomy**.  

  **Example Mobility File:**  

  | Code | Type     | Cost (€) | Autonomy (km) |
  |------|---------|---------|--------------|
  | M_1  | Scooter | 0.20    | 15           |
  | M_2  | Scooter | 0.20    | 13           |
  | M_3  | Car     | 0.80    | 320          |

### Core Functionalities  

1. **Insert & Remove Mobility Devices** (by ID)  
2. **Insert & Remove User Requests** (by ID)  
3. **List All Mobility Devices**  
4. **List All Usage Requests**  
5. **Calculate Usage Cost** (based on request ID)  
6. **Assign Mobility Devices to Users**  
   - Matches requests to available mobility devices, ensuring autonomy requirements are met  
   - If the requested device lacks sufficient autonomy, an alternative of the same type is assigned  
7. **Generate Mobility Usage Plans**  
   - Displays planned usage of a specific mobility device, sorted by request order  

   **Example Usage Plan for M_3:**  

   | Request No. | NIF       | Start Time | End Time | Autonomy (km) | Code |
   |------------|----------|-----------|----------|--------------|------|
   | 4          | 111222333 | 0         | 100      | 320          | M_3  |
   | 6          | 22223333  | 100       | 250      | 300          | M_3  |

### Data Storage  

- Save & retrieve **mobility requests** from files  
- Save & retrieve **mobility devices** from files  

## Technologies  

- **Language:** C  
- **Paradigm:** Imperative Programming  

## License  

This project is open-source and available under the **MIT License**.  
