void *
GetAddressByName
(const char *name)
{
	if (NULL == name) return NULL;
	else if (0 == strcmp(name, "DirectDrawCreate")) return (void *)DirectDrawCreate;
	else if (0 == strcmp(name, "DirectDrawCreateEx")) return (void *)DirectDrawCreateEx;
	return NULL;
}
