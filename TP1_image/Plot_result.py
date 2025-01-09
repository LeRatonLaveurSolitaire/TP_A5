import matplotlib.pyplot as plt
import numpy as np

# // temps matlab
# // V1 : 53.5ms
# // V2 : 11.3ms

# // temps C
# // ij : 101.724861
# // ji : 99.072701

# // temps Cuda
# // 48.971455

results_value = [53.5, 11.3, 29, 17, 14]
results_name = ["matlab_v1", "matlab_v2", "C_ij", "C_ji", "CUDA"]
results_color = ["b", "b", "r", "r", "g"]


def main():

    plt.figure(figsize=(10, 6))  # Set the figure size
    bars = plt.bar(results_name, results_value, color=results_color)

    # Customize the graph
    plt.title("Results")
    plt.ylabel("Time (ms)")

    # Add value labels on top of each bar
    for bar in bars:
        height = bar.get_height()
        plt.text(
            bar.get_x() + bar.get_width() / 2.0,
            height,
            f"{height}",
            ha="center",
            va="bottom",
        )

    plt.legend()

    # Show the graph
    plt.show()


if __name__ == "__main__":
    main()
