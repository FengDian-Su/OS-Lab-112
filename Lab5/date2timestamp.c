#include<linux/module.h>
#include<linux/time.h>

int d = 1, m = 1, y = 1;
long long int ts = 0;

module_param(d, int, 0);
MODULE_PARM_DESC(d, "date of time");
module_param(m, int, 0);
MODULE_PARM_DESC(m, "month of time");
module_param(y, int, 0);
MODULE_PARM_DESC(y, "year of time");

int init_module(void) {
	printk(KERN_INFO "date2timestamp insert successs\n");
	printk(KERN_INFO "%d/%d/%d\n", y, m, d);
	int mary[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
	if (m<1 | m>12 | d<1 | d>31) {
		printk(KERN_ERR "Invalid parameters");
		return -EINVAL;
	}
	ts = (y-1970)*31557600+(mary[m-1]+d-1)*86400;
	if (y<1970 | ts<0) {
		printk(KERN_INFO "Invalid argument.\n");
	} else {
		printk(KERN_INFO "ts = %lld\n", ts);
	}
	//printk(KERN_INFO "d2ts end\n");
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "remove success\n");
}

EXPORT_SYMBOL(ts);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("s4110056007");
MODULE_DESCRIPTION("oslab5: date2timestamp");
