import unittest
import unittest.mock

import blink.blink


class TestBlink(unittest.TestCase):
    """Test the blink.py module."""

    def setUp(self):
        """."""

        # Prepare mocks and patches
        self.pin_instance_mock = unittest.mock.Mock()
        self.pin_instance_mock.toggle = unittest.mock.Mock()
        self.pin_mock = unittest.mock.Mock(return_value=self.pin_instance_mock)
        self.pin_mock.OUT = "out"
        self.timer_instance_mock = unittest.mock.Mock()
        self.timer_instance_mock.init = unittest.mock.Mock()
        self.timer_mock = unittest.mock.Mock(return_value=self.timer_instance_mock)
        self.timer_mock.PERIODIC = "periodic"

        self.patch_pin = unittest.mock.patch(
            "blink.blink.blink.machine.Pin",
            self.pin_mock,
        )
        self.patch_timer = unittest.mock.patch(
            "blink.blink.blink.machine.Timer",
            self.timer_mock,
        )

        return super().setUp()

    def tearDown(self):
        """."""
        return super().tearDown()    

    def test_setup(self):
        """Test setup function creates a led pin for blinking."""
        with self.patch_pin:
            led = blink.blink.setup()

        self.assertEqual(self.pin_instance_mock, led)
        self.pin_mock.assert_called_once_with("LED", "out")

    def test_main(self):
        """Test main function runs required setups and starts the timer."""
        patch_setup = unittest.mock.patch(
            "blink.blink.setup",
            self.pin_mock,
        )

        with patch_setup, self.patch_timer:
            blink.blink.main()

        self.pin_mock.assert_called_once()
        self.timer_mock.assert_called_once()
        self.timer_instance_mock.init.assert_called_once_with(
            freq=2.5,
            mode="periodic",
            callback=blink.blink.tick,
        )

if __name__ == '__main__':
    unittest.main()
