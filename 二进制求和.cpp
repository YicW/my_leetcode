string addBinary(string a, string b) {
	auto c = '0';
	vector<char> result;
	if (a.size() < b.size())
	{
		auto temp = a;
		a = b;
		b = temp;
	}
	if (b.empty())
		return a;
	auto b_it = b.rbegin();
	for (auto a_it = a.rbegin(); a_it != a.rend(); a_it++)
	{
		if (b_it == b.rend())
		{
			if (*a_it == '1'&&c == '1')
			{
				result.push_back('0');
				c = '1';
			}
			else
			{
				if (c == '1')
				{
					result.push_back('1');
					c = '0';
					continue;
				}
				result.push_back(*a_it);
				c = '0';
			}
		}
		else
		{
			if (*a_it == '1'&&*b_it == '1'&&c == '1')
			{
				result.push_back('1');
				c = '1';
				b_it++;
			}
			else if ((*a_it == '1'&&*b_it == '1') || (*a_it == '1'&&c == '1') || (*b_it == '1'&&c == '1'))
			{
				bool flag = (*a_it == '1'&&*b_it == '1');
				result.push_back('0');
				c = '1';
				b_it++;
			}
			else
			{
				if (*a_it == '0'&&*b_it == '0'&&c == '0')
				{
					result.push_back('0');
					b_it++;
					continue;
				}
				result.push_back('1');
				c = '0';
				b_it++;
			}
		}

	}
	if (c == '1')
		result.push_back('1');
	string r(result.rbegin(), result.rend());
	return r;

}
