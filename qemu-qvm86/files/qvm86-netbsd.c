#include "qvm86.h"
#include <sys/conf.h>
#include <sys/proc.h>
#include <sys/lkm.h>
#include <sys/malloc.h>
#include <uvm/uvm.h>

/*
 * Copyright (c) 2006 Tobias Nygren <tnn@netilium.org>
 * This code is released into the public domain.
 */

dev_type_open (qvm86_open);
dev_type_close (qvm86_close);
dev_type_ioctl (qvm86_ioctl);

const struct cdevsw qvm86_cdevsw = {
	qvm86_open, qvm86_close, noread, nowrite, qvm86_ioctl,
	nostop, notty, nopoll, nommap, nokqfilter,
};

MOD_DEV("qvm86", "kqemu",  NULL, -1, &qvm86_cdevsw, 153);

static qvm86_state *qs = NULL;


/* Give other tasks a chance to run.  Returns nonzero if this task has
   signals pending.  */
int
host_do_sched (qvm86_state *qs)
{
	sigset_t s;

	/* XXX do we need to do scheduler stuff like on Linux? */

	sigpending1 (curproc, &s);
	return s.__bits[0]|s.__bits[1]|s.__bits[2]|s.__bits[3];
}

void *
host_alloc_zeroed (unsigned long size)
{
	return malloc (size, M_TEMP, M_ZERO);
}

void *
host_alloc_pages (int count)
{
	return (void*)uvm_km_alloc (kernel_map, count*PAGE_SIZE,
				    PAGE_SIZE, UVM_KMF_WIRED|UVM_KMF_ZERO);
}

void
host_free (void * ptr)
{
	free (ptr, M_TEMP);
}

void
host_free_pages (void * ptr, int count)
{
	uvm_km_free (kernel_map, (vaddr_t)ptr, count*PAGE_SIZE,
		     UVM_KMF_WIRED|UVM_KMF_ZERO);
}

host_physaddr_t
host_phys_addr (void * addr)
{
	paddr_t pa;
	if (!pmap_extract (pmap_kernel(), (vaddr_t)addr, &pa))
		panic ("host_phys_addr: invalid mapping");
	return pa;
}

/* Map user pages into kernel space.  */
/* XXX is there a better(faster, safer) way to do this? */
void
host_map_user (unsigned long useraddr, qvm86_mapped_page * map)
{
	vaddr_t va;
	paddr_t pa;
		
	if (uvm_fault_wire (&curproc->p_vmspace->vm_map, (vaddr_t)useraddr,
			    (vaddr_t)useraddr + PAGE_SIZE, VM_FAULT_WIRE,
			    VM_PROT_NONE))
		panic ("host_map_user: uvm_fault_wire");

	if (!pmap_extract(curproc->p_vmspace->vm_map.pmap, useraddr, &pa))
		panic ("host_map_user: pmap_extract");

	va = uvm_km_alloc (kernel_map, PAGE_SIZE, PAGE_SIZE, UVM_KMF_VAONLY);

	if (pmap_enter (pmap_kernel(), va, pa, 
			VM_PROT_READ|VM_PROT_WRITE|VM_PROT_EXECUTE,
			PMAP_WIRED) != 0)
		panic("host_map_user: pmap_enter");

	pmap_update();

	map->host = (void*)va;
	map->hostdata = (void*)useraddr;
	map->phys = pa;
}

/* Unmap a user page.  */
void
host_unmap_user (qvm86_mapped_page *map, int dirty)
{
	
	pmap_remove (pmap_kernel(), (vaddr_t)map->host, (vaddr_t)map->host + PAGE_SIZE);
	pmap_update();
	uvm_km_free (kernel_map, (vaddr_t)map->host, PAGE_SIZE, UVM_KMF_VAONLY);
	uvm_fault_unwire (&curproc->p_vmspace->vm_map,
			  (vaddr_t)map->hostdata,
			  (vaddr_t)map->hostdata + PAGE_SIZE);
}


/* Mark a user page as dirty.  */
void
host_mark_dirty (qvm86_mapped_page *map)
{
	printf ("host_mark_dirty\n");
}

int
qvm86_open(dev, flags, ifmt, l)
	dev_t dev;
	int flags, ifmt;
	struct lwp *l;
{
	printf ("qvm86_open\n");
	if(qs) return EBUSY;
	qs = host_alloc_zeroed (sizeof (qvm86_state));
	qvm86_init_device (qs);
	return (0);
}

int
qvm86_ioctl(dev, cmd, addr, flag, l)
	dev_t dev;
	u_long cmd;
	caddr_t addr;
	int flag;
	struct lwp *l;
{
	struct kqemu_cpu_state *kcpu = (struct kqemu_cpu_state*)addr;
	struct kqemu_init *kinit = (struct kqemu_init*)addr;

	switch (cmd) {
		case KQEMU_EXEC:
		     	kcpu->retval = qvm86_exec (qs, kcpu);
			if (qs->die) {
				printf ("qvm86_ioctl: qs->die\n");
				kcpu->retval = KQEMU_RET_ABORT;
			}
			break;

		case KQEMU_INIT:
			qvm86_init (qs, kinit);
			break;

		case KQEMU_GET_VERSION:
			*(int*)addr = KQEMU_VERSION;
			break;
			
		default:
			printf ("qvm86_ioctl: invalid\n");
			return (EINVAL);
	}
	return (0);
}

int
qvm86_close(dev, flags, ifmt, l)
	dev_t dev;
	int flags, ifmt;
	struct lwp *l;
{
	printf("qvm86_close\n");
	qvm86_cleanup_device (qs);
	host_free (qs);
	qs = NULL;
	return (0);
}
int
qvm86_lkm(struct lkm_table *lkmtp, int cmd)
{
	printf("qvm86_lkm\n");
	switch(cmd) {
		case LKM_E_LOAD:
			if (lkmexists(lkmtp)) return (EEXIST);
			break;
		case LKM_E_UNLOAD:
			if (qs) return (EBUSY);
			break;
	}
	return (0);
}

int
qvm86_lkmentry( lkmtp, cmd, ver)
	struct lkm_table *lkmtp;
	int cmd, ver;
{
	DISPATCH(lkmtp, cmd, ver, qvm86_lkm, qvm86_lkm, lkm_nofunc);
}
