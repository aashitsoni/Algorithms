import numpy as np

matrix_a = np.array([ [0,1,1,1,0,0,0,0],
                      [1,0,1,0,1,1,0,0],
                      [1,1,0,1,1,0,0,0],
                      [1,0,1,0,1,0,0,1],
                      [0,1,1,1,0,1,1,1],
                      [0,1,0,0,1,0,1,0],
                      [0,0,0,0,1,1,0,1],
                      [0,0,0,1,1,0,1,0] ] )

a2 = matrix_a @ matrix_a 

print("This is A2:")
print(a2)

a3 = a2@matrix_a

print("this is A3")
print(a3)