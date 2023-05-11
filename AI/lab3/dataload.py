import numpy as np

def generate_batches(X, y, batch_size):
    """
    X: np.array[n_objects, n_features] --- features
    y: np.array[n_objects] --- target
    """
    assert len(X) == len(y)
    np.random.seed(42)
    X = np.array(X)
    y = np.array(y)
    perm = np.random.permutation(len(X))

    for batch_start in range(0, len(X) - len(X) % batch_size, batch_size):
        indices_list = perm[batch_start : batch_start + batch_size]
        X_batch = [elem1 for elem1 in [X[j] for j in indices_list]]
        y_batch = [elem for elem in [y[i] for i in indices_list]]
        yield (X_batch, y_batch)