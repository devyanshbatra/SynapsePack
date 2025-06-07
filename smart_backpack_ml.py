import numpy as np
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

class LoadOptimizer:
    def __init__(self):
        self.model = LinearRegression()

    def generate_dummy_data(self):
        X = np.array([
            [5, 170, 20],
            [8, 165, 25],
            [6, 180, 22],
            [10, 175, 30],
            [12, 160, 35],
            [15, 155, 40]
        ])
        y = np.array([30, 35, 28, 40, 45, 50])
        return X, y

    def train_model(self):
        X, y = self.generate_dummy_data()
        self.model.fit(X, y)
        print("ML Model Trained: Linear Regression")

    def predict_strap_length(self, total_weight, user_height, user_age):
        input_data = np.array([[total_weight, user_height, user_age]])
        predicted = self.model.predict(input_data)
        return predicted[0]

    def show_graph(self):
        X, y = self.generate_dummy_data()
        weights = X[:, 0]
        plt.scatter(weights, y)
        plt.xlabel("Total Weight (kg)")
        plt.ylabel("Strap Length (cm)")
        plt.title("Weight vs Strap Length")
        plt.grid(True)
        plt.show()


if __name__ == "__main__":
    ml = LoadOptimizer()
    ml.train_model()
    predicted_length = ml.predict_strap_length(10, 170, 22)
    print(f"[ML Prediction] Suggested strap length: {predicted_length:.2f} cm")
    ml.show_graph()
