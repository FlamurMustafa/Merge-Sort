#include <iostream>
#include <vector>

using namespace std;

template<class T>
void merge(std::vector<T>& v, int p, int q, int r)
{
	int size1 = q - p + 1;
	int size2 = r - q;
	vector<T> L(size1);
	vector<T> R(size2);

	for (int i = 0; i < size1; i++)
	{
		L[i] = v[p + i];
	}
	for (int j = 0; j < size2; j++)
	{
		R[j] = v[q + j + 1];
	}

	int i = 0, j = 0;
	int k;
	for (k = p; k <= r && i < size1 && j < size2; k++)
	{
		if (L[i] <= R[j])
		{
			v[k] = L[i];
			i++;
		}
		else
		{
			v[k] = R[j];
			j++;
		}
	}
	for (i = i; i < size1; ++i)
	{
		v[k] = L[i];
		k++;
	}

	for (j = j; j < size2; j++)
	{
		v[k] = R[j];
		k++;
	}
}

template<class T>
void merge_sort(std::vector<T>& v, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(v, p, q);
		merge_sort(v, q + 1, r);
		merge(v, p, q, r);
	}
}

template<class T>
void InsertInt(vector<T>& v) {
	int x,y;
	cout << "Shtypni numrin e antereve: ";
	cin >> x;
	for (int i = 0; i < x; i++) {
		cout << "Shtypni antarin :" << i + 1<<": ";
		cin >> y;
		v.push_back(y);
	}
}
template<class T>
void InsertString(vector<T>& v) {
	int x;
	string y;
	cout << "Shtypni numrin e antereve: ";
	cin >> x;
	for (int i = 0; i < x; i++) {
		cout << "Shtypni antarin :" << i + 1<<": ";
		cin >> y;
		v.push_back(y);
	}
}
int main()
{
	vector<int>vec;
	vector<string>vec1;
	int x;
	cout << "Shtyp \n1-Per vektor me integjer\n2-Per vektor me stringje\n";
	cin >> x;
	if (x == 1) {
		InsertInt(vec);
		int sz = vec.size();
		cout << "Vektori i dhene : ";
		for (int n = 0; n < sz; n++)
		{
			cout << vec[n] << " ";
		}
		cout << "\n";
		cout << "Vektori i sortuar: ";
		merge_sort(vec, 0, sz - 1);
		for (int n = 0; n < sz; n++)
		{
			cout << vec[n] << " ";
		}
	}
	else {
		InsertString(vec1);
		int sz1 = vec1.size();
		cout << "Vektori i dhene : ";
		for (int n = 0; n < sz1; n++)
		{
			cout << vec1[n] << " ";
		}
		cout << "\n";
		cout << "Vektori i sortuar: ";
		merge_sort(vec1, 0, sz1 - 1);
		for (int n = 0; n < sz1; n++)
		{
			cout << vec1[n] << " ";
		}
		cout << "\n\n";
	}
	

	return 0;
}