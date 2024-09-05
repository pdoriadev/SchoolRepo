import time

###########################################################################
# uses the sleep function in-betwen each char output to brute-force a retro
#   real-time screen typing/loading.
def simulatedTypePrinting(output :str, timeScale :float = 1):
    if (len(output) == 0):
        return 
    
    for i in range(0, len(output)):       
        print(output[i], end = "")
        time.sleep(0.05 * timeScale * float(len(output)) / float(len(output) * len(output)))