#include <iostream>
#include <vector>

int main() {
    int K;
    std::cin >> K;

    for (int s = 0; s < K; ++s) {
        int n, L, T;
        std::cin >> n >> L >> T;

        std::vector<int> images;
        int conflits = 0;

        std::cout << "CIBLES " << n << " " << L;

        for (int u = 1; u <= T; ++u) {
            int image = (u - 1) % n;

            images.push_back(image);

            std::cout << " " << image;

            bool conflit = false;

            // Vérifions les L trames précédentes.
            for (int d = 1; d <= L; ++d) {
                int precedente = u - d;

                if (precedente >= 1 &&
                    (precedente - 1) % n == image) {
                    conflit = true;
                    break;
                }
            }

            if (conflit) {
                ++conflits;
            }
        }

        std::cout << "\n";
        std::cout << "CONFLITS "
                  << n << " " << L << " "
                  << conflits << "\n";
    }
  

    return 0;
}
