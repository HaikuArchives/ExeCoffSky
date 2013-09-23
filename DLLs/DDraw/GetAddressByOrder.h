void *
GetAddressByOrder
(int order)
{
	switch (order) {
	case 7:		return (void *)DirectDrawCreate;
	case 10:	return (void *)DirectDrawCreateEx;
	}
	return NULL;
}
