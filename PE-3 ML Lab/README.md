ML Lab (college practical)
commands:

1️⃣ Set Path / Import Libraries: 
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


2️⃣ Load Dataset (Path)
If dataset is in same folder
df = pd.read_csv("dataset.csv")

If dataset is in a folder
df = pd.read_csv("data/dataset.csv")


3️⃣ Display Dataset
df.head()

df.tail()

df.shape

df.columns


4️⃣ Dataset Information
df.info()

df.describe()


5️⃣ Check Missing Values
df.isnull().sum()

Handle missing values (example)
df.fillna(df.mean(), inplace=True)


6️⃣ Separate Features and Target
X = df.drop("target_column", axis=1)
y = df["target_column"]


7️⃣ Train-Test Split
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)


8️⃣ Model Selection (Example: Logistic Regression)
from sklearn.linear_model import LogisticRegression

model = LogisticRegression()
model.fit(X_train, y_train)


9️⃣ Prediction
y_pred = model.predict(X_test)


🔟 Accuracy / Evaluation
Classification
from sklearn.metrics import accuracy_score, confusion_matrix

accuracy = accuracy_score(y_test, y_pred)
accuracy

confusion_matrix(y_test, y_pred)

