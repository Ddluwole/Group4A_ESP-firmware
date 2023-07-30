from machine import Pin, DAC

# Define the ADC range and voltage output range
adc_min = 0          # Minimum value of the input range
adc_max = 255       # Maximum value of the input range
voltage_min = 0.0    # Minimum voltage output 
voltage_max = 3.3    # Maximum voltage output 

# Pin connected to the DAC
dac_pin = 25  

# Initialize the DAC
dac = DAC(Pin(dac_pin))

def map_value(value, in_min, in_max, out_min, out_max):
    # Function to map a value from one range to another
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

def set_voltage(voltage):
    # Set the voltage output on the DAC and call the map_value function
    dac_value = int(map_value(voltage, voltage_min, voltage_max, adc_min, adc_max))
    dac.write(dac_value)

# Sample test of my code written before the python script that supplies values is ready
# Convert input value (0 to 255) to corresponding voltage output (0V to 3.3V)
input_value = 50 
voltage_output = map_value(input_value, 0, 100, voltage_min, voltage_max)
set_voltage(voltage_output)
