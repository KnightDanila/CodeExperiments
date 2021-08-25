template<class iter, class T>
void for_each(iter first, iter last, T& sum)
{
	for(;first!=last; ++first)
	{
		if((*first)>0)
		{
			sum=sum+(*first);
		}
	}

};

