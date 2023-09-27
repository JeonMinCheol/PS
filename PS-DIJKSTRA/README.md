# dijkstra
### vector< pair<int, int> >v[1000]; 이런식으로 처음 vector를 생성할 때 크기를 상수로 정의하고 시작한다면 ,
#### for (int i = 0; i < m; i++) {
####	int a, b, c;
####	cin >> a >> b >> c;
####	v[a].push_back({ b,c });
#### }
### 이런게 가능하다. 왜인지는 잘 모르겠다.

### 그리고 이런식으로 vector를 정의했다면, 함수의 인자로 들어갈 때 vector< pair<int, int> > v[]로 들어가야 평소에 사용하던 것 처럼 쓸 수 있다. 마찬가지로 왜인진 모른다.
