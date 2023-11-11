#include<linux/module.h>
#include<linux/time.h>

extern long long int ts;
long long int temp = 1000000000, born;
int cy, cd;

int init_module(void) {
	printk(KERN_INFO "myage insert success\n");
	//printk(KERN_INFO "pass ts = %lld\n", ts);
	born = ktime_get_real()/temp-ts;
	if (born<0) {
		printk(KERN_INFO "Are you kidding me :)\n");
		return 0;
	}
	//printk(KERN_INFO "born = %lld\n", born);
	cd = (born%31557600)/86400;
	cy = born/31557600;
	printk(KERN_INFO "You have survived %d years and %d days.\n", cy, cd);
	//printk(KERN_INFO "myage end\n");
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "myage remove success\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("s4110056007");
MODULE_DESCRIPTION("oslab5: myage");
