#include <iostream>
#include <iomanip>

struct Vecteur {
    double x;
    double y;
    double z;
};

struct Quaternion {
    double x;
    double y;
    double z;
    double w;
};

struct Pose {
    Vecteur position;
    Quaternion rotation;
};

Vecteur appliquerPose(const Pose& pose, const Vecteur& point) {
    double x = point.x;
    double y = point.y;
    double z = point.z;

    double qx = pose.rotation.x;
    double qy = pose.rotation.y;
    double qz = pose.rotation.z;
    double qw = pose.rotation.w;

    // Rotation du point par le quaternion
    double rx = (1 - 2 * qy * qy - 2 * qz * qz) * x
              + (2 * qx * qy - 2 * qz * qw) * y
              + (2 * qx * qz + 2 * qy * qw) * z;

    double ry = (2 * qx * qy + 2 * qz * qw) * x
              + (1 - 2 * qx * qx - 2 * qz * qz) * y
              + (2 * qy * qz - 2 * qx * qw) * z;

    double rz = (2 * qx * qz - 2 * qy * qw) * x
              + (2 * qy * qz + 2 * qx * qw) * y
              + (1 - 2 * qx * qx - 2 * qy * qy) * z;

    // Puis translation
    return {
        rx + pose.position.x,
        ry + pose.position.y,
        rz + pose.position.z
    };
}

int main() {
    Pose pose;
    Vecteur point;

    // Position de la pose
    std::cin >> pose.position.x
             >> pose.position.y
             >> pose.position.z;

    // Quaternion : x y z w
    std::cin >> pose.rotation.x
             >> pose.rotation.y
             >> pose.rotation.z
             >> pose.rotation.w;

    // Point
    std::cin >> point.x
             >> point.y
             >> point.z;

    Vecteur resultat = appliquerPose(pose, point);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << resultat.x << " "
              << resultat.y << " "
              << resultat.z << '\n';

    return 0;
}
