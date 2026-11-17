import blink.machine


def tick(timer):
    led.toggle()


def setup():
    """Set up the blink program."""
    led = blink.machine.Pin("LED", blink.machine.Pin.OUT)
    return led


def main():
    """The main program loop"""
    global led
    led = setup()
    tim = blink.machine.Timer()
    tim.init(freq=2.5, mode=blink.machine.Timer.PERIODIC, callback=tick)


if __name__ == "__main__":
    main()
