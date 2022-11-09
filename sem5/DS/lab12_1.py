# written by gaurav r
# CS20B1021, LAB 12 Q1

import numpy as np
import matplotlib.pyplot as plt

random_sizes = [10, 100, 500, 1000, 5000, 10000, 50000]


def gen_random_exponential(
    size=100,
):  # Function to generate random dataset for exponentially distribution
    dataframe = np.random.exponential(size=size, scale=1.0)
    dataframe = np.array([round(x, 2) for x in dataframe])
    return dataframe


gen_random_exponential()


def gen_random_uniform(
    size=100,
):  # Function to generate random dataset for Uniform Distribution
    dataframe = np.random.uniform(0, 2, size=size)
    dataframe = np.array([round(x, 2) for x in dataframe])
    return dataframe


gen_random_uniform()


def gen_random_bernoulli(
    size=100,
):  # Function to generate random dataset for Bernoulli Distribution
    dataframe = np.random.binomial(1, 0.5, size=size)
    dataframe = np.array([round(x, 2) for x in dataframe])
    return dataframe


gen_random_bernoulli()


def plotsm_expo(
    random_sizes,
):  # Function for exponential distribution plot respect to their mean
    means = [np.mean(gen_random_exponential(a)) for a in random_sizes]
    plt.plot(random_sizes, means)
    plt.xlabel("Sample Size")
    plt.ylabel("Sample Mean")
    plt.title("Exponential Distribution Sample Mean Plot")
    plt.show()


plotsm_expo(random_sizes)


def plotsm_unif(
    random_sizes,
):  # Function for uniform distribution plot respect to their mean
    means = [np.mean(gen_random_uniform(a)) for a in random_sizes]
    plt.plot(random_sizes, means)
    plt.xlabel("Sample Size")
    plt.ylabel("Sample Mean")
    plt.title("Uniform Distribution Sample Mean Plot")
    plt.show()


plotsm_unif(random_sizes)


def plotsm_bernauli(
    random_sizes,
):  # Function for bernoulli distribution plot respect to their mean
    means = [np.mean(gen_random_bernoulli(a)) for a in random_sizes]
    plt.plot(random_sizes, means)
    plt.xlabel("Sample Size")
    plt.ylabel("Sample Mean")
    plt.title("Bernoulli Distribution Sample Mean Plot")
    plt.show()


plotsm_bernauli(random_sizes)
