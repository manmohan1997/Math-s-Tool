# Math-s-Tool
#This tool is used to find the input data set from a data pool and then determine the corresponding dependent parameter using interpolation 
A pool of data is created using the data obtained from the CFD simulation over an aerofoil (pressure data over selected location on Aerofoils which acts as pressure ports). The pressure data was collected for various flow conditions .i.e. different angle of attack and different mach numbers.
Now random 5 pressure inputs were given as an input ( which will be similar in original flight condition input given to flush air data system)
These inputs are compared to the data present at each node of the datapool carpet(multidimensional arrays)
After making a comparison throgh calculating the average of MSE (mean square error ) for each data it identifies a quadrant .i.e a box like domian.
After detemining the box it uses reverse bilinear interpolation to determine the mach and angle of attack for the given data set.
Power point presentation can be used for more detailed explanantion.
