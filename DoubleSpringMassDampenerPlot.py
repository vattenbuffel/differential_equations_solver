import pygame

pipe_path = 'pipe_double_spring_dampener'

STATE_MESSAGE_TYPE = 0
STATE_ARRAY_START = 1
STATE_P1 = 2
STATE_V1 = 3
STATE_P2 = 4
STATE_V2 = 5
STATE_ARRAY_END = 6
STATE_T = 7

MESSAGE_TYPE_FIRST = 0
MESSAGE_TYPE_MIDDLE = 1
MESSAGE_TYPE_FINAL = 2

p1s = []
v1s = []
p2s = []
v2s = []
ts = []
s1 = 0
s2 = 0
prev_line = None
state = STATE_MESSAGE_TYPE
last_data_received = False

# Constants
WINDOW_WIDTH = 800
WINDOW_HEIGHT = 600
SPRING_COLOR = (255, 0, 0)
SPRING_WIDTH = 5
MASS_RADIUS = 20
BACKGROUND_COLOR = (255, 255, 255)
TEXT_COLOR = (0, 0, 0)
COIL_SEGMENT_LENGTH = 0.2

# Initialize pygame
pygame.init()
screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
pygame.display.set_caption("Double Spring Dampener Simulation")

# Set up font
font = pygame.font.SysFont(None, 36)

# Function to draw a spring
def draw_spring(surface, x1, y1, x2, y2, width, color, num_coils):
    points = []
    for i in range(num_coils + 1):
        t = i / num_coils
        x = (1 - t) * x1 + t * x2
        y = (1 - t) * y1 + t * y2
        if i % 2 == 0:
            x += 10
        else:
            x -= 10
        points.append((x, y))
    pygame.draw.lines(surface, color, False, points, width)

# Function to draw text
def draw_text(surface, text, x, y, color):
    img = font.render(text, True, color)
    surface.blit(img, (x, y))

# Main loop
clock = pygame.time.Clock()
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
                p1s = []
                v1s = []
                p2s = []
                v2s = []
                ts = []
                last_data_received = False
            elif f"{MESSAGE_TYPE_FINAL}" in data:
                last_data_received = True
            state = STATE_ARRAY_START
        elif state == STATE_ARRAY_START:
            state = STATE_P1
        elif state == STATE_P1:
            p1s.append(float(data[0]))
            state = STATE_V1
        elif state == STATE_V1:
            v1s.append(float(data[0]))
            state = STATE_P2
        elif state == STATE_P2:
            p2s.append(float(data[0]))
            state = STATE_V2
        elif state == STATE_V2:
            v2s.append(float(data[0]))
            state = STATE_ARRAY_END
        elif state == STATE_ARRAY_END:
            state = STATE_T
        elif state == STATE_T:
            ts.append(float(data[2].replace(",", "")))
            s1 = float(data[5].replace(",", ""))
            s2 = float(data[8].replace(",", ""))
            state = STATE_MESSAGE_TYPE

            # Process and display all collected data
            if not last_data_received:
                continue

            dt = ts[2] - ts[1]
            fps = 1/dt
            for i in range(len(p1s)):
                screen.fill(BACKGROUND_COLOR)  # Clear the screen before redraw
                # Calculate positions
                y10 = 10
                y11 = int(-p1s[i] * 50) + y10
                x1 = WINDOW_WIDTH / 2
                y2 = int(-(p2s[i] - p1s[i]) * 50) + y11
                x2 = WINDOW_WIDTH / 2

                # Draw the springs
                s1_coil_segments = int(s1//COIL_SEGMENT_LENGTH)
                s2_coil_segments = int(s2//COIL_SEGMENT_LENGTH)
                draw_spring(screen, x1, y10, x1, y11, SPRING_WIDTH, SPRING_COLOR, s1_coil_segments)
                draw_spring(screen, x2, y11, x2, y2, SPRING_WIDTH, SPRING_COLOR, s2_coil_segments)

                # Draw masses
                pygame.draw.circle(screen, SPRING_COLOR, (x1, y11), MASS_RADIUS)
                pygame.draw.circle(screen, SPRING_COLOR, (x2, y2), MASS_RADIUS)

                # Draw positions as text
                draw_text(screen, f"p1: {p1s[i]:.2f}", x1 + 30, y11, TEXT_COLOR)
                draw_text(screen, f"p2: {p2s[i]:.2f}", x2 + 30, y2, TEXT_COLOR)
                draw_text(screen, f"fps: {fps:.2f}", 10, 10, TEXT_COLOR)

                pygame.display.flip()
                clock.tick(fps)  # Limit to desired FPS
            aiotenhaoinh = 5

pygame.quit()
