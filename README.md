# baekjoon

백준

------그리디 알고리즘-----
2138번 전구 https://www.acmicpc.net/problem/2138
바꿔야 하는 전구와 목표하는 전구가 다를 경우 바꿔야 하는 다음 전구를 바꾸는 간단한 아이디어가 필요
그리디라는 사실에 힌트를 얻어 아이디어가 떠오르기는 했으나 첫 전구와 마지막 전구를 어떻게 처리해야 되나 고민함
이 고민에 대한 해결 방법도 간단하다 첫 전구를 눌렀을 때, 안 눌렀을 때 두 가지 경우를 만들어
최소한으로 누른 경우가 답이 된다
n이 100,000이고 시간 복잡도가 O(N)이 나오기 때문에 두 가지 경우를 만드는건 충분히 가능하다
제한 시간이 2초를 준게 약간의 힌트가 될 수 있었던 것 같다


11000번 강의실 배정 https://www.acmicpc.net/problem/11000
모든 강의를 다 들어야 한다. 우선 시간이 가장 빠른 강의로 정렬한다
가장 먼저 시작하는 강의가 가장 먼저 끝나는 강의보다 빠르면 강의실을 한개 더 추가해야 한다
그렇지 않으면 가장 먼저 끝나는 강의를 빼고 강의실을 사용하면 된다
추가된 강의실을 사용하지 않는다고 답이 줄어드는 것이 아니기 때문에 추가된 강의실을 활용해야 한다는
아이디어만 떠오르면 쉽게 풀릴듯 알고리즘 분류가 그리디로 되어있지만 정렬, 우선순위 큐 또한 사용한다

2437번 저울 https://www.acmicpc.net/problem/2437
제시된 저울을 순서에 따라 정렬한다 순서에 따라 저울을 뽑는데 
새로 뽑힌 저울이 기존 저울들의 합보다 큰 경우 측정할 수 없는 양의 무게가 발생한다
예를 들어 기존 저울들의 합을 이용해 1부터 x까지 측정 가능하다 할 때 
새로 뽑은 저울이 x보다 큰 y라 한다면(y>x+n)
이 저울들로는 x+1의 무게를 측정하지 못한다
반대로 y가 x보다 작다면 1부터 x+y까지 측정 가능해진다
이 아이디어를 떠올릴 수 있냐가 문제를 풀 수 있는지 결정짓는 핵심이다

1946번 신입 사원 https://www.acmicpc.net/problem/1946
첫번째 등수로 정렬을 하고난 이후 순서대로 비교하는 알고리즘을 설계했다
비교할 때 두번째 등수를 첫번째 등수가 높은 경우 일일히 비교하려 했다 
이때 문제점은 시간복잡도가 O(N*N)이 된다는 점 즉 시간초과 시간복잡도를 줄여야 했다.
해결 방법은 첫번째 등수로 정렬을 하고 전부다 비교하는게 아닌
이미 최근에 뽑힌 사람의 두번째 등수만 비교하면 된다는 사실이다 
순서대로 정렬하면 이미 첫번째 등수는 낮기 때문에 뽑히기 위해 두번쨰 등수가 높아야 하는데
최근에 뽑힌 사람보다 두번째 등수가 높다는 사실은 
두번째 등수가 높은 사람이 뒷 순서에 있더라도 첫번째 등수는 현재 순서가 높기 때문에 뽑힘을 보장한다
O(N)에 해결 가능해진다

1541번 잃어버린 괄호 https://www.acmicpc.net/problem/1541
'-'가 나오면 뒤에있는 숫자는 무조건 빼주면 된다
ex)100-(50+100)-10, 100-(50+100)-(10+3)-20
'-'등장 후 괄호를 묶으면 뒷수는 무조건 음수가 된다

1339번 단어 수학 https://www.acmicpc.net/problem/1339
알파벳을 자리 수만 비교하여 더해 정렬한 후 ex)(100A+10A+1A)+(100A+10A+1A)
높은 순서대로 9부터 1까지 차례대로 대입하면 최대값이 나오게 된다.
간단한 아이디어로 풀 수 있는 쉬운 문제였으나 
아이디어를 생각하지 않고 바로 문제를 풀려고 하여 풀지 못했던 것 같다.
또한 아이디어를 떠올랐어도 
알파벳 26자리를 순서대로 정렬해야 하는데 total length를 만들어 삽질을 하게되었다
총 정렬해야 하는 범위는 0부터 25까지이다 for문을 쓸 때 범위를 신경써야 한다.

1715번 카드 정렬하기 https://www.acmicpc.net/problem/1715
가장 작은 두 수끼리 더하면 최소값으로 비교할 수 있다는 아이디어가 필요하다
아이디어는 떠올랐으나 정렬을 사용하여 풀어 문제를 틀렸다
단순하게 생각하여 10 20 30 40 을 정렬하여 두 값을 선택하여 더하면 최소가 된다고 생각하여 틀렸다
위 방식에 반례를 들자면 10 30 35 37 같은 경우는 (10+30)+(35+37)+(40+72)가 답이된다
10 30 35 37
35 37 40
40 72...
따라서 문제를 풀기위해 정렬이 아닌 우선순위 큐를 사용해야한다
문제를 너무 일차원적으로 접근하여 문제를 풀지 못한듯 하다 
다양한 경우의 수를 생각하고 고민해야한다

1080번 행렬 https://www.acmicpc.net/problem/1080
좌표 (x, y)에서 행렬 a와 행렬 b가 다를 경우 바꿔줘야 하는데
(x, y)를 기준으로 다를경우 (x+3, y+3)안에 들어있는 수를 모두 바꿔주는 그리디한 방법을 선택하면 된다
이러한 방법은 (x-1)행과 (y-1)열에 영향을 주지 않는다
2138번과 비슷한 아이디어로 풀 수 있는 문제이다

12904번 A와 B https://www.acmicpc.net/problem/12904
문제를 읽고 bfs로 풀려고 했다. (큐에 주가지 연산을 넣어 비교하는 방식으로)
메모리 초과라는 결과가 나와 다시 생각했다. 
해결 아이디어는 생각보다 간단하게 나타났다
S에서 T를 만드는게 아니라 T에서 S로 만드는 것이다
T의 끝자리가 A이면 pop back하면 되고
끝자리가 B이면 pop back후 뒤집어 주면 된다
그 상태에서 S와 T의 크기가 같아질 때 두 문자열을 비교하면 된다
생각보다 간단한 아이디어로 풀리는 문제이다 

13164번 행복 유치원 https://www.acmicpc.net/problem/13164
사이 수들의 차이를 저장하여 정렬하는 간단한 문제이다
사이 차들을 정렬한 배열을 순서대로 뽑기만 하는 아이디어를 얻기가 쉽지 않았다
즉 차가 가장 큰 거 k-1개 선택해서 빼면 된다
한번 뽑을 때마다 하나씩 묶이기 때문에 n-k번만 반복하면 된다
ex)100+a을 b개로 만들기 위해선 (100+a)-(b)번 반복
----------------------------------------------------------------------------
