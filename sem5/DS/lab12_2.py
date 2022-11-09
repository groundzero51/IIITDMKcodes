# written by gaurav r
# CS20B1021, LAB 12 Q2

import numpy as np
import matplotlib.pyplot as plt


def gen_random_exponential(
    size=1000,
):  # Function to generate random dataset for exponentially distribution
    dataframe = np.random.exponential(size=size, scale=1.0)
    dataframe = np.array([round(x, 2) for x in dataframe])
    return dataframe


gen_random_exponential()


def gen_random_uniform(
    size=1000,
):  # Function to generate random dataset for uniform distribution
    dataframe = np.random.uniform(0, 2, size=size)
    dataframe = np.array([round(x, 2) for x in dataframe])
    return dataframe


gen_random_uniform()


def gen_random_bernauli(
    size=1000,
):  # Function to generate random dataset for bernauli distribution
    dataframe = np.random.binomial(1, 0.5, size=size)
    dataframe = np.array([round(x, 2) for x in dataframe])
    return dataframe


gen_random_bernauli()

sizes = [1, 2, 4, 8, 16, 32]
dataframe_expo = gen_random_exponential()
sum_expo = 0
for x in dataframe_expo:
    sum_expo += x
mean_expo = sum_expo / 1000
sum_expo = 0
for x in dataframe_expo:
    sum_expo += (x - mean_expo) ** 2
std_expo = (sum_expo / 1000) ** (1 / 2)


def verify_clt_exponential():
    mean = [np.mean(gen_random_exponential(n)) for n in sizes]
    normal = [(x - mean_expo) / (std_expo / (1000**1 / 2)) for x in mean]
    plt.plot(mean, normal)
    plt.xlabel("Sample mean")
    plt.ylabel("normal Approximation")
    plt.title("Exponential Distribution CLT Verification")
    plt.show()


verify_clt_exponential()
dataframe_unif = gen_random_uniform()
sum_unif = 0
for x in dataframe_unif:
    sum_unif += x
mean_unif = sum_unif / 1000
sum_unif = 0
for x in dataframe_unif:
    sum_unif += (x - mean_unif) ** 2
std_unif = (sum_unif / 1000) ** (1 / 2)


def verify_clt_uniform():
    mean = [np.mean(gen_random_uniform(n)) for n in sizes]
    normal = [(x - mean_unif) / (std_unif / (1000**1 / 2)) for x in mean]
    plt.plot(mean, normal)
    plt.xlabel("Sample mean")
    plt.ylabel("normal Approximation")
    plt.title("Uniform Distribution CLT Verification")
    plt.show()


verify_clt_uniform()
dataframe_bernauli = gen_random_bernauli()
sum_bernauli = 0
for x in dataframe_bernauli:
    sum_bernauli += x
mean_bernauli = sum_bernauli / 1000
sum_bernauli = 0
for x in dataframe_bernauli:
    sum_bernauli += (x - mean_bernauli) ** 2
std_bernauli = (sum_bernauli / 1000) ** (1 / 2)


def verify_clt_bernauli():
    mean = [np.mean(gen_random_bernauli(n)) for n in sizes]
    normal = [(x - mean_bernauli) / (std_bernauli / (1000**1 / 2)) for x in mean]
    plt.plot(mean, normal)
    plt.xlabel("Sample mean")
    plt.ylabel("normal Approximation")
    plt.title("Bernoulli Distribution CLT Verification")
    plt.show()


verify_clt_bernauli()
