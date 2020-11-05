## Wheeled sports robot
My entry for the 2019 AUT robotics competition / FIRA U19 wheeled sports robot league.
Regrettably, the final status for this robot was DNF - due to reasons unbeknownst to me, the robot stopped working a few seconds after the round started, despite operating optimally 5 hours before the competition. This might have occured because of battery wear, as a voltage below 7.2V would theoretically cause issues within *most* of this circuitry. Another reason would be electromagnetic interference, as it is a common (!) practice in my nation's robotic competitions to place a 1/3 phase line beneath the competition field in order to unscrupulously influence the results of the competition.

### Objectives
The robot must follow a black line on a white surface with occasional cut-offs and overlaps (without any contrast inversions) from the "start" marker till the "finish"
marker. There are 5 "objectives" marked with color-coded vinyl stickers on the right or left side of the black line; the robot must complete these objectives to collect
scores, then return to the main path. The objective and its sticker are on the same side of the path.

* Blue: Laps. There is a detour from the main black line ~100mm after this sticker; it forms a circuit in conjunction with a small (200-300mm) portion of the main path.
        this circuit has to be lapped 3 times.
* Green: Football. There is a detour perpendicular to the main path after this sticker; the robot must follow this new path and stop after detecting a black line (perpendicular to the new path). There is a table-tennis-sized ball in front of this line which must be shot into one of the 3 goals. There is a black sticker on the side of the detour. If the sticker is on the right side, shooting into the right goal has extra points (shooting into the left goal has no points). The opposite applies if the sticker is on the left side.
* Yellow: Archery. The robot must take a detour, stop before a black line and shoot an arrow at a target sheet. The projectile is not supposed to penetrate the target but leave enough of a mark to allow scoring (my arrowheads were soft but covered in ink).
* Red: Deadlift. The robot must take a detour, stop briefly before a black line, then move forward to a second black line, lift a ~500g weight from a short platform, move forward to a third black line and place the weight on a higher platform.
* Silver: Push. The robot must take a detour and push a/an (I believe ~900g) MDF slab until it reaches a silver line.

### BOM
2x MG90s servos for pong-style handles (Football) 
1x MG90s servo for the arrow release mechanism
1x stepper (NEMA17, 1.2 Kg.cm) (Deadlift) w/ 1x A4988 chopping stepper driver
2x generic (yellow..?) plastic gearbox (1:120) DC motors (propulsion) w/ 1x L298N driver
11x TCRT5000 IR sensors (line detection)
2x TCS3200 color sensors  (objective detection)
1x 1602 LCD w/ IIC protocol (debugging, setup, color calibration, ...)
1x Arduino Mega 2560 R3 

### Methodology

### Photos

(I will upload .stl files for the 3d-printed parts when I find them)
        
