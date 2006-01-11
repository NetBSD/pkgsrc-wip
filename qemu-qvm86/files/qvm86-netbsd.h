#ifndef QVM86_NETBSD_H
#define QVM86_NETBSD_H

/* NetBSD specific header files */

#include <sys/systm.h>
#include <sys/types.h>
#include <sys/param.h>
#include <uvm/uvm_extern.h>

#define asmlinkage
#define printk printf
#define clear_page(x) bzero(x, PAGE_SIZE)
#define __get_user(x, ptr) copyin(ptr, &x, 4)
#define KERN_ERR "qvm86 error: "
#define KERN_INFO "qvm86 info: "

#define qvm86_host_pae 0
#define host_physaddr_t paddr_t

#endif /* QVM86_NETBSD_H */
