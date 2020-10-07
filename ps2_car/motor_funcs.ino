
//电机控制相关

//电机A前进pwm值
int motoAForwardValue(int leftYValue) {
    if (isMiddleValue(leftYValue)) {
        return 0;
    }

    if (leftYValue > 127) {
        return 0;
    }

    leftYValue = 127 - leftYValue;

    return map(leftYValue, 0, 127, 0, 255);
}

//电机A 倒退pwm值， 反转
int motoABackwardValue(int leftYValue) {
    if (isMiddleValue(leftYValue)) {
        return 0;
    }

    if (leftYValue < 128) {
        return 0;
    }

    leftYValue = leftYValue - 128;

    return map(leftYValue, 0, 127, 0, 255);
}

void stopMotoA() {
  analogWrite(MotoAIn1, 0);
  analogWrite(MotoAIn2, 0);  
}

void stopMotoB() {
  analogWrite(MotoBIn1, 0);
  analogWrite(MotoBIn2, 0);  
}
