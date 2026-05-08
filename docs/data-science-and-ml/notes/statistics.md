# Statistics
Statistics is divided into two main parts:
1. **Descriptive Statistics** - working with data we already have (Mean, Median, Mode, Variance)
2. **Inferential Statistics** - using a small sample of data to make guesses about larger population (Hypothesis testing, P-values)

## A. Descriptive Statistics
### Types of data

#### - Numerical (Quantitative): Numbers
Can be **discrete**: countable things (integers) or **continuous**: measurable things (float)
#### - Categorical (Qualitative): Groups
Can be **nominal**: no order (eg. colors, city names) or **ordinal**: has a clear order (eg. education level)

### Central Tendency
How we represent data (the middle)
#### Mean (Average):
Add all values, divide by the count
Eg. a = [1, 2, 3, 4, 5], mean = (1 + 2 + 3 + 4 + 5) / 3 = 3

#### Median:
The exact middle when sorted
Eg. a = [1, 2, **3**, 4, 5], median = 3

#### Mode:
The most frequent value.
Eg. a = [1, 2, 3, **4**, **4**, 5], mode = 4

---

### Measure of Spread
If Central Tendency is about the middle, the Spread is about how messy and scattered the data is.

#### Variance (σ^2)
Variance measures how far apart are the values from the mean.
- **High Variance** - values are spread out (eg. salaries of $20k, $50k, $200k)
- **Low Variance** - values are close to each other (eg. salaries of $49k, $50k, $51k)

##### The formula is: the average of the squared deviations
1. Eg a = [1, 2, 3, 4, 5], mean = 3
2. Subtract each number with the mean: a = [-2, -1, 0, 1, 2], these are the deviations
3. Square each number: a = [4, 1, 0, 1, 4]
4. Add and calc average: Variance = (4 + 1 + 1 + 4) / 5 = 2.5

#### Standard Deviation (σ)
The square root of Variance. It's used to bring back numbers to original unit, making it easier to talk about

#### Range
Range = Maximum Value - Minimum Value

---

### Data Distribution
This is how we find the shape of the data.

#### The Normal Distribution (The Bell Curve)
- The left side is a mirror image of the right
- The Mean, Median, Mode are all the same
- The Empirical Rule: (68 - 95 - 99.7)
  - 68% of all data points fall within 1σ (Standard Deviation) of the mean
  - 95% fall within 2σ
  - 99.7 fall within 3σ

#### Skewness (The Tail)
The skew is where the tail is. It shows where the data is pulled

- Right (Positive) Skew: the tail stretches to the right
  Eg. Income. Most people earn moderate amount (the hump) but a few billionares pull the tail and the Mean way to the right
- Left (Negative) Skew: the tail stretches to the left
  Eg. Age of Death. Most people die at an older age (the hump) but a few die young, pulling the tail and the Mean to the left.


## B. Inferential Statistics
### Hypothesis Testing & P-Values

#### The Null Hypothesis (H0)
It assumes nothing changed, or there is no effect.
Eg. This new medicine doesn't work.

#### The Alternative Hypothesis (H1)
It;s what you're trying to prove.
Eg. This new medicine does work.

#### The P-Value
The p-value is the probability that your results happened by pure random chance, assuming the medicine actually does nothing (H0 is true).

Low P-Value (usually <0.05): The result is so weird that it's probably not luck. We Reject the Null. (The medicine works!)

High P-Value (>0.05): The result could easily be luck. We Fail to Reject the Null.

#### Significance Level (α)
This is the threshold you set before the experiment. Most scientists use 0.05 (5%). It means you are willing to accept a 5% risk of being wrong.

### Type I and Type II Errors
1. Type I Error (False Positive)
   
Definition: You reject the Null Hypothesis (H0), but the Null was actually true.

In Court: An innocent person is found guilty.

Symbol: α (Alpha).

1. Type II Error (False Negative)

Definition: You fail to reject the Null Hypothesis (H0), but the Null was actually false.

In Court: A guilty person is set free.

Symbol: β (Beta).


### Confidence
A Confidence Interval (CI) is a range of values we are fairly sure it contains the true answer

#### The 95% confidence rule
In Data Science, it's usually Mean ± (2 * Standard Error)


