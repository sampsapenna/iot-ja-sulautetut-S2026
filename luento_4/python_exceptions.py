import typing


class SensorState(typing.TypedDict):
    """Dictionary for keeping the sensor state."""

    measurement_started: bool
    ready: bool


class SensorExceptions(Exception):
    """Main class for sensor related exceptions."""


class SensorUnavailable(SensorExceptions):
    """Exception to be raised when the sensor is unavailable."""


class SensorOutOfRange(SensorExceptions):
    """Sensor is determined to be out of range."""


def example_raiser():
    try:
        1 / 0
    except ZeroDivisionError as e:
        print("Can't divide by zero!")
        raise e


def divide_numbers(a: int, b: int) -> float:
    """Divide a by b."""
    try:
        return a / b
    except Exception as e:
        print(f"Got exception {e}.")
        return 0.0


def check_sensor_ready(state: SensorState) -> bool:
    return state["ready"]
