def f_by_a(i, n):
    return ((1 + i) ** n - 1) / i


def a_by_f(i, n):
    return 1 / f_by_a(i, n)


def p_by_a(i, n):
    return f_by_a(i, n) / ((1 + i) ** n)


def a_by_p(i, n):
    return 1 / p_by_a(i, n)


def f_by_p(i, n):
    return (1 + i) ** n


def p_by_f(i, n):
    return 1 / ((1 + i) ** n)


def f_linearG(A, increment, i, n):
    return (A + increment * (1 / i - n / ((1 + i) ** n - 1))) * f_by_a(i, n)


def p_linearG(A, increment, i, n):
    return f_linearG(A, increment, i, n) * p_by_f(i, n)


def cr(I, s, i, n):
    return I * a_by_p(i, n) - s * a_by_f(i, n)


def mv(I, s, i, n, n_remaining):
    """
    Returns the market value.

    I: investment
    s: salvage value
    i: interest rate
    n: useful life period
    n_remaining: remaining useful life period
    """
    return cr(I, s, i, n) * p_by_a(i, n_remaining) + s * p_by_f(i, n_remaining)


def uib(I, i, n, r, e=0):
    """
    Returns a list of Unrecovered Investment Balance.

    I: investment
    i: interest rate
    n: number of periods
    r: revenue per period;
            can be a number for uniform revenue or,
            a list containing revenue for each period
    e: expense per period;
            can be a number for uniform expense or,
            a list containing expense for each period
    """
    if type(r) != list:
        r = [r] * n
    if type(e) != list:
        e = [e] * n

    def uib(n):
        if n == 1:
            return I
        else:
            return uib(n - 1) * (1 + i) - (r[n - 2] - e[n - 2])

    return [round(uib(j), 3) for j in range(2, n + 2)]


def senstivity():
    """
    Call the function to perform senstivity analysis
    """

    def npv(I, r, e, n, i, s):
        return -I + (r - e) * p_by_a(i, n) + s * p_by_f(i, n)

    values = input(
        "Enter the Investment, Annual Revenue, Annual Expense, number of time periods, interest rate, and salvage value separated by commas:\n"
    ).split(",")
    for index, item in enumerate(float(value) for value in values):
        for delta in [-0.4, -0.3, -0.2, -0.1, 0, 0.1, 0.2, 0.3, 0.4]:
            command = (
                ", ".join(values[:index])
                + f", {item*(1+delta)}, "
                + ", ".join(values[index + 1 :])
            )
            if command.startswith(","):
                command = command[2:]
            if command.endswith(", "):
                command = command[:-2]
            command = "npv(" + command + ")"
            print(command, " = ", end="")
            print(eval(command))
        print("\n")
