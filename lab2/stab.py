if __name__ == '__main__':
    n = 5
    #intensity = generate_matrix(n)
    intensity = get_pre_def_intensity(n)

    start_probabilities = get_start_probabilities(n, False)

    # Нахождение предельных вероятностей
    probability = solve_linalg.solve(intensity)
    output('Предельные вероятности:', 'p', probability)

    # Нахождение времени стабилизации
    stabilization_time = stabilization.calc_stabilization_times(intensity, start_probabilities, probability)
    times, probabilities_over_time = stabilization.calc_probability_over_time(intensity, start_probabilities, 5)
    output('Время стабилизации:', 't', stabilization_time)

    # Вывод графа связей и весов
    graph.graph(intensity)
    # Вывод графиков вероятностей как функции времени
    graph.graph_probability_over_time(probability, stabilization_time, times, probabilities_over_time)