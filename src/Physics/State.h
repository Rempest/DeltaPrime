struct State {
    double x = 0;
    double v = 0;
    double a = 0;
};

struct State {
    double x = 0, y = 0, z = 0;
    double vx = 0, vy = 0, vz = 0;
    double ax = 0, ay = 0, az = 0;
    double roll = 0, pitch = 0, yaw = 0;

    void reset() {
        x=0; y=0; z=0;
        vx=0; vy=0; vz=0;
        ax=0; ay=0; az=0;
        roll=0; pitch=0; yaw=0;
    }
};