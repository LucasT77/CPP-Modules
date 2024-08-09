// 42 header

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template < typename T >
class	Array
{
	public:

		Array( ) : _size( 0 ), _array( new T[0]() )
		{	}

		Array( unsigned int n ) : _size( n ), _array( new T[n]() )
		{	}

		Array( const Array<T>& copy ) : _size( copy.size() ), _array( new T[copy.size()]() )
		{
			for ( size_t i = 0; i < copy.size(); i++ )
				this->_array[i] = copy._array[i];
		}

		~Array( void )
		{
			if ( this->_array )
				delete[] this->_array;
			this->_array = NULL;
		}

		Array<T>&	operator =( const Array<T>& assign )
		{
			if ( this != &assign )
			{
				if ( this->_array )
					delete[] this->_array;
				this->_size = assign.size();
				this->_array = new T[ assign.size() ]();
				for ( size_t i = 0; i < assign.size(); i++ )
					this->_array[i] = assign._array[i];
			}
			return	*this;
		}

		unsigned int	size() const
		{
			return	this->_size;
		}
		
		T& operator	[](unsigned index) const
		{
			if ( index >= this->_size || !this->_array)
				throw	std::out_of_range( "Invalid memory access" );
			return	this->_array[ index ];
		}

	private:
		unsigned int	_size;
		T				*_array;
};

template <typename T>
std::ostream& operator <<( std::ostream& lhs, Array<T>& rhs )
{
	lhs << "[" ;
	for ( size_t i = 0; i < rhs.size(); ++i )
		lhs << " " << rhs[i] << ",";
	lhs << "]";
	return	lhs;
}

#endif
