import numpy as np
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score, classification_report
import matplotlib.pyplot as plt

# Create a synthetic dataset
X, y = make_classification(
    n_samples=300,    # Number of samples
    n_features=4,     # Number of features
    n_informative=3,  # Number of informative features
    n_redundant=0,    # Number of redundant features
    n_classes=3,      # Number of classes
    random_state=42
)

# Split the data for classification
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Standardize the data
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Support Vector Machine (SVM)
svm = SVC(kernel='linear', random_state=42)
svm.fit(X_train_scaled, y_train)
svm_predictions = svm.predict(X_test_scaled)
print("SVM Accuracy:", accuracy_score(y_test, svm_predictions))
print(classification_report(y_test, svm_predictions))

# K-Nearest Neighbors (KNN)
knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(X_train_scaled, y_train)
knn_predictions = knn.predict(X_test_scaled)
print("KNN Accuracy:", accuracy_score(y_test, knn_predictions))
print(classification_report(y_test, knn_predictions))

# KMeans Clustering
kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X)
print("KMeans Cluster Centers:\n", kmeans.cluster_centers_)
print("KMeans Predicted Labels for X:\n", kmeans.labels_)

# Visualize the dataset (first two features for simplicity)
plt.figure(figsize=(12, 6))

# Plot ground truth
plt.subplot(1, 2, 1)
plt.scatter(X[:, 0], X[:, 1], c=y, cmap='viridis', edgecolor='k', s=50)
plt.title('True Labels')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')

# Plot KMeans predictions
plt.subplot(1, 2, 2)
plt.scatter(X[:, 0], X[:, 1], c=kmeans.labels_, cmap='viridis', edgecolor='k', s=50)
plt.title('KMeans Clustering')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')

plt.tight_layout()
plt.show()
