void *
GetAddressByOrder
(int order)
{
	switch (order) {
	case 1:		return (void *)DirectSoundCreate;
	}
	return NULL;
}
