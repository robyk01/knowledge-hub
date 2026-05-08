a) Nondeterministic Algorithm
We try to guess a candidate and verify the majority element.

function(a, n):
    choose x from a

    cnt = 0
    for i = 1 to n do
        if a[i] == x then
            cnt = cnt + 1

    if cnt > n/2 then
        success
        return x
    else
        failure

b) Las Vegas Algorithm
The algorithm always produces a correct result but has variable running time

function(a, n):
    while true do
        i = random.uniform(1, n)
        x = a[i]

        cnt = 0
        for j = 1 to n do
            if a[j] == x then
                cnt = cnt + 1

        if cnt > n/2 then
            return x

If the element is not a majority element just loop again and choose another one

c) Monte Carlo Algorithm
The algorithm has fixed running time but probabilistic correctness

function(a, n):
    k = 250

    for i = 1 to k do
        i = random.uniform(1, n)
        x = a[i]

        cnt = 0
        for j = 1 to n do
            if a[j] == x then
                cnt = cnt + 1

        if cnt > n/2 then
            return x

    return failure

If the algorithm doesnt find a majority element after 250 iterations (k), return failure
