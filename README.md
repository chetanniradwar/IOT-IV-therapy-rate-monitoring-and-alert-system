# IOT-IV-therapy-rate-monitoring-and-alert-system
## Introduction
1.  Due to busy schedule of nurses and doctors, it becomes very difficult for them to constantly observe the volume of liquid inside the bag.
2.  Depending on the consumption rate the bag can take 2 to 3 hrs or more to drain.
3.  It is difficult to constantly observe the bottle at night. If it is not handled in correct time then there can be chances of reverse flow of blood.
4.  In this project a IR trans-receiver pair is used to detect the drops falling down in drip chamber. The NodeMCU counts the drops and time between two consecutive drops. This data is used to calculate time remaining, volume remaining, drop rate, etc. 
5.  This calculated data is sent to Google's Firebase database through HTTP connection. From database, data is fetched in android app.
6.  The android app shows all the details and also generates the alerts (notification and sound) when the liquid inside the bag is about to drain.

## Circuit Diagram

### 1.Power Supply
<img src="images/IOT_circuit_1.png" width="50%"><img>

### 2.MCU
<img src="images/IOT_circuit_2.png" width="50%"><img>

## Android App 
<img src="images/app_img_1.png" width="20%"><img> | <img src="images/app_img_2.png" width="20%"><img> | <img src="images/alert_img.png" width="20%" height="100%"><img>

* The application is developed using MIT app Inventor

## Database
<img src="images/database_img.png" width="25%"><img>

## Result
<img src="images/result_img.png" width="50%"><img>
