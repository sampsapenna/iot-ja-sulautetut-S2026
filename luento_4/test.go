package test


import (
	"fmt"
)


func TestFunction(in string) (string, err) {
	errStr, err := fmt.Errorf("Got error %s", in)
}
