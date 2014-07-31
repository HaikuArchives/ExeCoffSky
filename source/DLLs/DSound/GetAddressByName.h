void *
GetAddressByName
(const char *name)
{
	if (NULL == name) return NULL;
	else if (0 == strcmp(name, "DirectSoundCreate")) return (void *)DirectSoundCreate;
	return NULL;
}
