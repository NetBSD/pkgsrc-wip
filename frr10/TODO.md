TODO for frr10:

- Requires sys/netinet/ip_mroute.h,v 1.36 or later.
  - Does not compile on NetBSD 10.1 or earlier.
  - Does compile on netbsd-10, netbsd-11 and -current.
  - Could provide via a patch, perhaps, if deemed reasonable and/or
    necessary and/or useful.
- Needs more rc.d scripts to cover all daemons, or adapting tools/frr
  from upstream instead.  (Leaning towards the latter.)
