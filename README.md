# Hello 

## Unit circle differential equation
The unit circle can be defined using differential equations.  
x = cos(t)  
y = sin(t)  

If we think of t as a third variable, the angle we can write differentiate w.r.t t,this leads to  
x_dot = -sin(t)  
y_dot = cos(t)  

This can then be solved using RK1 for example. To do so and plot the results run these commands   
Terminal 1  
```
mkfifo pipe_unit_circle
cd src/unit_circle/RK1
mkdir build
cd build
cmake ..
make
cd ..
while true; do ./build/main > ../../../pipe_unit_circle; sleep 1; done
```

Terminal 2  
```
python UnitCirclePlot.py
```