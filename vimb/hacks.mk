# $NetBSD: hacks.mk,v 1.1 2013/10/11 16:46:47 leot1990 Exp $

.if !defined(VIMB_HACKS_MK)
VIMB_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

### [Tue Oct  1 12:10:05 CEST 2013 : leot]
### On NetBSD the LOCK_* macros in <fcntl.h> are defined if and only if is
### defined _NETBSD_SOURCE.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*)
CPPFLAGS+=	-D_NETBSD_SOURCE
.endif

.endif	# VIMB_HACKS_MK
