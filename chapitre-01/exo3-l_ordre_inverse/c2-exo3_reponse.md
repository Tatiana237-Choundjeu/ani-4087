#include <iostream>
#include <iomanip>
#include <cmath>

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

// Fonction qui fait la rotation d'un point
Vecteur tourner(const Quaternion& q, const Vecteur& point) {
    double x = point.x;
    double y = point.y;
    double z = point.z;

    double qx = q.x;
    double qy = q.y;
    double qz = q.z;
    double qw = q.w;

    return {
        (1 - 2*qy*qy - 2*qz*qz)*x
        + (2*qx*qy - 2*qz*qw)*y
        + (2*qx*qz + 2*qy*qw)*z,

        (2*qx*qy + 2*qz*qw)*x
        + (1 - 2*qx*qx - 2*qz*qz)*y
        + (2*qy*qz - 2*qx*qw)*z,

        (2*qx*qz - 2*qy*qw)*x
        + (2*qy*qz + 2*qx*qw)*y
        + (1 - 2*qx*qx - 2*qy*qy)*z
    };
}

// 1. Rotation puis translation
Vecteur appliquerPose(const Pose& pose, const Vecteur& point) {
    Vecteur p = tourner(pose.rotation, point);

    return {
        p.x + pose.position.x,
        p.y + pose.position.y,
        p.z + pose.position.z
    };
}

// 2. Translation puis rotation
Vecteur appliquerPoseInverse(const Pose& pose, const Vecteur& point) {
    Vecteur p = {
        point.x + pose.position.x,
        point.y + pose.position.y,
        point.z + pose.position.z
    };

    return tourner(pose.rotation, p);
}

int main() {
    Pose pose;
    Vecteur point;

    // Position de la pose
    std::cin >> pose.position.x
             >> pose.position.y
             >> pose.position.z;

    // Quaternion x y z w
    std::cin >> pose.rotation.x
             >> pose.rotation.y
             >> pose.rotation.z
             >> pose.rotation.w;

    // Point
    std::cin >> point.x
             >> point.y
             >> point.z;

    Vecteur resultat1 = appliquerPose(pose, point);
    Vecteur resultat2 = appliquerPoseInverse(pose, point);

    std::cout << std::fixed << std::setprecision(4);

    // Rotation puis translation
    std::cout << resultat1.x << " "
              << resultat1.y << " "
              << resultat1.z << '\n';

    // Translation puis rotation
    std::cout << resultat2.x << " "
              << resultat2.y << " "
              << resultat2.z << '\n';

    return 0;
}
