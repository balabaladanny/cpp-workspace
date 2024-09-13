# TODO: Split the data into training and validation sets
# Note: please follow template for the format of return variables
def train_val_split(X, y, val_size=0.2, random_state=None):
    """
    Splits the data into training and validation datasets.

    Parameters:
    - X: Features data
    - y: Target data
    - val_size: Proportion of data to be used for validation
    - random_state: Seed for reproducibility

    Returns:
    - X_train: Features for the training data
    - X_val: Features for the validation data
    - y_train: Target for the training data
    - y_val: Target for the validation data
    """

    # Ensure reproducibility
    np.random.seed(random_state)

    # Create an array of indices from 0 to len(X) - 1
    indices = np.arange(len(X))

    # Shuffle these indices to randomize the data split
    np.random.shuffle(indices)

    # Calculate the number of validation samples
    val_size = int(len(X) * val_size)

    # Split the indices into training and validation indices
    val_indices = indices[:val_size]
    train_indices = indices[val_size:]

    # Use the indices to create the training and validation sets
    X_train = X.iloc[train_indices]
    X_val = X.iloc[val_indices]
    y_train = y.iloc[train_indices]
    y_val = y.iloc[val_indices]

    # X_train = X[train_indices]
    # X_val = X[val_indices]
    # y_train = y[train_indices]
    # y_val = y[val_indices]

    return X_train, X_val, y_train, y_val