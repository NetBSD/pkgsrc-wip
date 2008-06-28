# $NetBSD: hacks.mk,v 1.1.1.1 2008/06/28 05:37:33 bsadewitz Exp $
#
.if !empty(EDB_HACKS_MK)
EDB_HACKS_MK=	# defined
.  include "../../mk/compiler.mk"

.  if !empty(CC_VERSION:Mgcc-[34]*)
PKG_CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.  endif
.endif
