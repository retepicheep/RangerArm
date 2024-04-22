# Setup Steps
Setup Steps for VScode.
I think I am missing steps and might need to edit this doc in the futur stay posted!

## 1) Download the Arduino Extension and Arduino-CLI

1) Download the arduino extension.

2) Either Download the Arduino-CLI or use the bundled one. If you use the bundled one skip to the Download libraries step.

## 2) Configure Arduino-CLI
     
 Go to VScode settings. Search for the arduino settings.

 1) Put `arduino-cli` into the command path.

 2) Put the path to the arduino-cli minus the file name into the Arduino:Path field.

 3) create a build folder in the RangerArm folder. *Note:* Do NOT put *anything* in the folder.

## 3) Download Libraries

Run the scripts in your terminal.

```
arduino-cli lib install Stepper
```
```
arduino-cli lib install Servo
```
```
arduino-cli lib install LiquidCrystal
```
```
arduino-cli lib install LedControl
```
```
arduino-cli lib install HC-SR04
```

## 4) Set Up Board

1) Click on `<Select Board>` and select the first arduino mega option.

2) Click on `<Select Port>` and select the port your arduino is plugged into.

## 5) Click Upload

this should upload and give you no problems, however, I think I am missing steps and might need to edit this doc in the futur stay posted!
