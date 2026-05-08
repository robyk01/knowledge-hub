# Machine Learning
We use machine learning to make predictions around the data we have.

## Supervised Learning
When we have a set of data and provide x **the input** and y **the label**. The goal for the model is to create a relationship so that it can label data it hasn't seen before.

- Regression
  Predicting a continuous number. Eg. predicting a house price
- Classification
  Predicting a discrete category. Eg. predicting if an email is spam or not

## Unsupervised Learning
We only provide the inputs and let the model set labels based on patterns and structures

- Clustering
  Grouping similar data points together. Eg classifying movies based on category
- Dimensionality Reduction
  Simplifying complex data. 

## Linear Regression
It's a supervised learning algorithm used to predict a continuous dependent variable. We draw a line and try to make it go straight through the middle of data points in a graph.

**Formula**: y = mx + b

### Loss Function
The computer uses a loss function to measure how wrong it is. For regression, we usually use **MSE** (Mean Squared Error).
To know if the line we drew is good or not:
- It looks at the residuals (the distance between the line and data points)
- If the dots are far from the line, the loss is high
- If the dots hug the line, the loss is low
- It squares the distance and takes the average of them


### Gradient Descent
To find the best line, the computer needs to minimize the MSE. It uses an algorithm called Gradient Descent.
It's the vector of partial derivatives. We move in the opposite direction to find the minimum error.


## Logistic Regression
It's a supervised learning algorithm used to predict a discrete variable. This is the most popular algorithm for Binary Classification (Eg spam filtering).
In Linear Regression our line (mx + b) can go to infinity. In Classification, we need a probability between 0 and 1.

To fix this, we pass the mx + b result through a Sigmoid Function:
σ(z) = 1 / (1 + e⁻ᶻ)
- If the mx + b is a huge positive number, the Sigmoid turns into 0.99 (99% probability)
- If it's a huge negative number, it turns into 0.01 (1% probability)
- If it's exactly 0, it turns into 0.5 (50% probability)

By default, the model uses 0.5 as the cutoff:
- Prob ≥ 0.5 -> Class 1
- Prob < 0.5 -> Class 0

## Decision Trees
Instead of drawing lines, here we ask questions. It is intuitive because it mirrors how people think.

The model looks at all your features (eg. Age, Income, Salary) and asks questions to split data into the purest groups:
- **The Root Node**: Asks the first question (eg. Is age > 30?)
- **The Leaf Nodes**: The final pockets where the prediction is made (Eg. Will buy or Won't buy)

### Gini Impurity
Measures how mixed a group is.
- If a group is 50% "pass" and 50% "fail": the impurity is high
- If a groups is 100% "pass": impurity is zero
- **The goal is to minimize the Gini Impurity at each step in the tree**

### Overfitting
Decision Trees are greedy, they will ask questions until each person in the training data has its own leaf. Because of this, decision trees fail to predict unseen data. This is **High Variance**.
To fix this, we prune the tree or set a max_depth, limiting the number of questions.

## Random Forest
Instead of one tree, we build 100 trees, choosing a random subset of the data with a random subset of the features. Some trees will be wrong, but averaging them will cancel the errors out.
This results in much lower variance than a simple tree (less overfitting).

## XGBoost
Trees here are built sequentially. Tree 2 is built to fix the errors from Tree 1. Tree 3 is built to fix Tree 2 and so on. It boosts performance by fixing the hard examples that the previous tree got wrong. This gives high accuracy but it's easy to overfit.

## Bias-Variance Tradeoff
**Bias** (Underfitting) = Model is too simple (eg. using a straight line for curved data). High error on both training and test data.
**Variance** (Overfitting) = Model is too complex (eg. decision tree with 100 levels). Low error on training, but high error on test data.

## Evaluation Metrics
### Classification
- **Precision**: Used when the cost of False Positives is high (eg. marking safe email as spam)
- **Recall**: Used when the cost of False Negatives is high (eg. marking spam email as safe)
- **F1-Score**: the harmonic mean of both, best for imbalanced data

### Regression
- **MSE**: Mean Squared Error (punishes outliers)
- **MAE**: Mean Absolute Error
- **RMSE**: Square Root of the MSE (puts the error back in the same unit as before)

## Cross Validation and Hyperparameter Tuning
### K-Fold Cross Validation
Instead of one train/test split, we split the data into K parts (folds). We train the data K times, each time with a different fold. It proves models aren't just lucky with a specific data split.

### Hyperparameters
Settings we choose before training (like max_depth for Decision Trees or learning_rate).
- **Grid Search**: Trying every combination of settings (slow)
- **Random Search**: Trying random combinations (might be faster)

## Other Algorithms
1. **K-Nearest Neighbours (KNN)**
To predict a point, it looks at the K closest data points. It is sensitive to scale, so we must normalize data.

2. **Support Vector Machines**
It tries to find the maximum margin to separate 2 classes. If the data isn't separable by a simple line in 2D, SVMs lift the data into a higher dimension (3D) to find a way to slice it.

3. **K-Means Clustering**
You tell the model to find K groups. It places K center points and pulls nearby data into them.

4. **Principal Component Analysis (PCA)**
It squashes 100 features into 2 or 3 "Principal Components" that capture most variance. It's used to speed up training, save memory, or visualize 100D data on a 2D plot.

