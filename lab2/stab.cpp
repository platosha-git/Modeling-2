int main()
{
    n = len(matrix)
    current_time = 0
    current_probabilities = start_probabilities.copy()
    stabilization_times = [0 for i in range(n)]

    total_lambda_sum = sum([sum(i) for i in matrix]) * MAGIC_NUM
    cool_eps = [p/total_lambda_sum for p in limit_probabilities]

    while not all(stabilization_times):
        curr_dps = dps(matrix, current_probabilities)
        for i in range(n):
            if (not stabilization_times[i] and curr_dps[i] <= cool_eps[i] and
                    abs(current_probabilities[i] - limit_probabilities[i]) <= cool_eps[i]):
                stabilization_times[i] = current_time
            current_probabilities[i] += curr_dps[i]

        current_time += TIME_DELTA

    return stabilization_times
}