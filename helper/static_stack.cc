namespace oostubs {

template<class T, int N>
class Stack
{
	public:
		Stack() {this->pos = 0;};

		void push(T obj) {
			if(pos >= N)
				return;
			vector[pos] = obj;
			++pos;
		};

		void pop() { if(pos > 0) --pos;};
		T top() { return vector[pos-1]; };
		bool empty() { return !pos;};
	private:
		T vector[N];
		int pos;
};
}
