// 내 생각의 흐름
// 일단 swap횟수를 세기 위해서 i번째 원소 기준으로 i + 1 ~ 끝까지 원소중에서 자신보다 작은 원소 갯수를 다 세서
// 더하면 됨
// 그렇다면 이제는 i번째 원소를 기준으로 i + 1부터 끝까지 중 작은게 몇 개인지를 빠르게 세야 됨
// 일단 가장 단순한 방법인 이중 for문은 O(N^2)을 그냥 봐도 안됨
// 그래서 대강 NlgN정도로 해야 겠다고 생각했고 vector를 이용해서 뒤에서부터 세면
// 자기 뒤로 정렬하고(nlgn), lower_bound(nlgn)찾아주면 되긴함
// 근데 sort과정은 배열이 이미 정렬된 경우 최악의 시간복잡도인 n^2이 되버리는데 내 코드상 항상 최악의 경우라서 시간초과가 남
// 그래서 이진검색트리를 이용하면 좋겠다고 생각함. 근데 STL의 map, set으로는 X보다 작은 원소 세는게 불가능
// 그래서 트립 구현해서 해결하게 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
vector<int> vnums;
struct Node {
	int key;
	int priority, size;
	Node* left, * right;
	Node(const int& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void calcSize()
	{
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
};
typedef pair<Node*, Node*> NodePair;
NodePair split(Node* root, int key)
{
	if (root == NULL) return NodePair(NULL, NULL);
	if (root->key < key)
	{
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}
Node* insert(Node* root, Node* node)
{
	if (root == NULL) return node;
	if (root->priority < node->priority)
	{
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (root->key < node->key)
		root->setRight(insert(root->right, node));
	else
		root->setLeft(insert(root->left, node));
	return root;
}
int cntLessThan(Node* root, int key)
{
	if (root == NULL) return 0;
	if (root->key >= key)
		return cntLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + cntLessThan(root->right, key);
}
void solve()
{
	cin >> N;
	vnums.push_back(0);
	int num;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		vnums.push_back(num);
	}
	Node* root = nullptr;
	long long cnt = 0;
	for (int i = N; i >= 1; i--)
	{
		cnt += cntLessThan(root, vnums[i]);
		root = insert(root, new Node(vnums[i]));
	}
	cout << cnt << endl;
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
