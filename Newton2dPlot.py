import os
import matplotlib.pyplot as plt

pipe_path = 'pipe_newton_2d'

STATE_MESSAGE_TYPE = 0
STATE_ARRAY_START = 1
STATE_P = 2
STATE_V = 3
STATE_ARRAY_END = 4
STATE_T = 5

MESSAGE_TYPE_FIRST = 0
MESSAGE_TYPE_MIDDLE = 1

ps = []
vs = []
ts = []
prev_line = None
state = STATE_MESSAGE_TYPE

# Open the named pipe for reading
with open(pipe_path, 'r') as pipe:
    # Clear any old data left in pipe
    pipe.flush()

    while True:
        # Read data from the named pipe
        data = pipe.readline().split()
        if not data:
            continue
        
        if state == STATE_MESSAGE_TYPE:
            if f"{MESSAGE_TYPE_FIRST}" in data:
                ps = []
                vs = []
                ts = []
                plt.pause(5)
            state = STATE_ARRAY_START
            continue
        if state == STATE_ARRAY_START:
            state = STATE_P
            continue
        elif state == STATE_P:
            ps.append(float(data[0]))
            state = STATE_V
            continue
        elif state == STATE_V:
            vs.append(float(data[0]))
            state = STATE_ARRAY_END
            continue
        elif state == STATE_ARRAY_END:
            state = STATE_T
            continue
        elif state == STATE_T:
            ts.append(float(data[2]))
            state = STATE_MESSAGE_TYPE
            plt.clf()
            plt.plot(ts, ps)
            plt.plot(ts, vs)
            plt.legend(["p", "v"])
            plt.show(block=False)
            plt.pause(0.000001)
            continue