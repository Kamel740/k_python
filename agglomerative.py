{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "from sklearn.cluster import AgglomerativeClustering\n",
    "from sklearn.model_selection import train_test_split\n",
    "from sklearn.datasets import load_breast_cancer\n",
    "import matplotlib.pyplot as p\n",
    "import scipy.cluster.hierarchy as s\n",
    "\n",
    "dataset =load_breast_cancer()\n",
    "\n",
    "x=dataset.data\n",
    "\n",
    "x_train,x_test=train_test_split(x, test_size=0.2,random_state=0)\n",
    "\n",
    "model=AgglomerativeClustering(n_clusters=4,metric=\"euclidean\")\n",
    "\n",
    "predictions= model.fit_predict(x_train)\n",
    "predictions2=model.fit_predict(x_test)\n",
    "predictions2\n",
    "\n",
    "dendrogram=s.dendrogram(s.linkage(x_train[:20], method=\"ward\"))\n",
    "\n",
    "dendrogram=s.dendrogram(s.linkage(x_test [:20], method=\"ward\"))\n",
    "\n",
    "p.scatter(x_train [predictions ==0,0],x_train[predictions ==0,1],c=\"red\")\n",
    "p.scatter(x_train[predictions ==1,0], x_train[predictions ==1,1],c=\"blue\")\n",
    "p.scatter(x_train[predictions ==2,0],x_train[predictions ==2,1],c=\"green\")\n",
    "p.scatter(x_train[predictions ==3,0], x_train[predictions ==3,1],c=\"black\")\n",
    "\n",
    "\n",
    "p.scatter(x_test [predictions2 ==0,0],x_test[predictions2 ==0,1],c=\"red\")\n",
    "p.scatter(x_test[predictions2 ==1,0], x_test[predictions2 ==1,1],c=\"blue\")\n",
    "p.scatter(x_test[predictions2 ==2,0],x_test[predictions2 ==2,1],c=\"green\")\n",
    "p.scatter(x_test[predictions2 ==3,0], x_test[predictions2 ==3,1],c=\"black\")"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "Code By ChatGpt"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "import numpy as np  \n",
    "import matplotlib.pyplot as plt  \n",
    "from scipy.cluster.hierarchy import dendrogram, linkage, fcluster  \n",
    "\n",
    "# إنشاء بيانات عشوائية  \n",
    "np.random.seed(0)  \n",
    "data = np.random.rand(25, 2)  # 10 نقاط في بعدين  \n",
    "\n",
    "# حساب الروابط باستخدام طريقة 'ward'  \n",
    "linked = linkage(data, method='ward')  \n",
    "\n",
    "# رسم شجرة التجميع  \n",
    "plt.figure(figsize=(10, 7))  \n",
    "dendrogram(linked,   orientation='top',   distance_sort='descending',   show_leaf_counts=True)  \n",
    "plt.title('Dendrogram')  \n",
    "plt.xlabel('Index')  \n",
    "plt.ylabel('Distance')  \n",
    "plt.show()  \n",
    "\n",
    "# تحديد عدد العناقيد  \n",
    "num_clusters = 3  \n",
    "clusters = fcluster(linked, num_clusters, criterion='maxclust')  \n",
    "\n",
    "# رسم النقاط الملونة حسب العناقيد  \n",
    "plt.figure(figsize=(8, 5))  \n",
    "plt.scatter(data[:, 0], data[:, 1], c=clusters, cmap='prism')  # استخدم الألوان لتمييز العناقيد  \n",
    "plt.title('Agglomerative Clustering Results')  \n",
    "plt.xlabel('Feature 1')  \n",
    "plt.ylabel('Feature 2')  \n",
    "plt.show()"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": ".venv",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.12.2"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
