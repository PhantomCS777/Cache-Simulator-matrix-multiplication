import os 
import sys 
import matplotlib.pyplot as plt


# Get a list of all .txt files in the current directory
file_list = [file for file in os.listdir() if file.endswith(".txt")]

# Initialize a list to store the legends
legends = []

# Iterate over each file
for file in file_list:
    # Read the data from the file
    with open(file, "r") as f:
        data = f.readlines()
    
    # print(data)
    x = [(line.split(',')[0]) for line in data]
    y = [(line.split(',')[1]) for line in data]
    x = list(map(int,x))
    y = list(map(float,y))
 
    plt.plot(x, y)
    legends.append(file)
    

plt.legend(legends)
plt.grid(True)  # Add grid lines
plt.xlabel('Value of n')
plt.ylabel('Time taken (s)')
plt.savefig("mult-benchmark.png")
plt.show()
