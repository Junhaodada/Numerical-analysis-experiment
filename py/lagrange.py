"""拉格朗日插值法"""


def lagrange(x0, y0, x) -> list:
    """拉格朗日插值函数"""
    y = []
    n = len(x0)
    m = len(x)
    for i in range(m):
        z = x[i]
        s = 0.0
        for k in range(n):
            p = 1.0
            for j in range(n):
                if(j != k):
                    p *= (z-x0[j])/(x0[k]-x0[j])
            s += p*y0[k]
        y.append(s)
    return y


if __name__ == "__main__":
    x1 = [0.2, 0.4, 0.6, 0.8, 1.0]
    y1 = [0.98, 0.92, 0.81, 0.64, 0.38]
    i = [0, 1, 11, 10]
    x2 = [0.2+0.08*j for j in i]
    print(lagrange(x1, y1, x2))
