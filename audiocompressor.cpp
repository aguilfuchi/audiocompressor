#include <iostream>
#include <cmath>

class Compressor {
private:
    double threshold; // Threshold level above which compression starts
    double ratio;     // Compression ratio
public:
    Compressor(double th, double r) : threshold(th), ratio(r) {}

    // Compress audio signal
    double compress(double input) {
        if (input > threshold) {
            return threshold + (input - threshold) / ratio;
        } else {
            return input;
        }
    }
};

int main() {
    // Example usage
    double threshold = 0.5; // Set threshold level
    double ratio = 2.0;     // Set compression ratio

    Compressor compressor(threshold, ratio);

    // Simulate input audio signal
    double inputSignal[] = {0.2, 0.6, 0.8, 0.3, 0.7, 0.9};

    // Apply compression to each sample of the input signal
    for (double sample : inputSignal) {
        double compressedSample = compressor.compress(sample);
        std::cout << "Original: " << sample << " Compressed: " << compressedSample << std::endl;
    }

    return 0;
}
