import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.datasets import load_iris
iris = load_iris()
type (iris)
print(iris.feature_names)
print(iris.target)
np.unique(iris.target)
print(iris.data.shape)
from sklearn.model_selection import train_test_split
x = iris.data
y = iris.target
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size =0.20, random_state = 4)
print(x_train.shape)
print(x_test.shape)
print(y_train.shape)
print(y_test.shape)
from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors = 5)
knn.fit(x_train , y_train)
y_pred = knn.predict(x_test)
print(y_pred)
len(y_pred)
from sklearn import metrics
ac = metrics.accuracy_score(y_test ,y_pred)
print(ac)
knn.predict([[5.8,2.7,5.1,1.9]])
knn.predict([[1,2,1,2]])
print("Mohamed Sayed Hafez")
