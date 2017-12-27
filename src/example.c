#include <sys/kernel_types.h>
#include <sys/systm.h>
kern_return_t example_start(kmod_info_t * ki, void *d) {
	printf("Loaded example\n");
	return KERN_SUCCESS;
}

kern_return_t example_stop(kmod_info_t *ki, void *d) {
	printf("example unloading.\n");
	return KERN_SUCCESS;
}
