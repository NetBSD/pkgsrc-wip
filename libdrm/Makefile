# $NetBSD: Makefile,v 1.10 2008/11/04 08:44:23 bsadewitz Exp $
#

DISTNAME=		libdrm-2.4.1
CATEGORIES=		x11 graphics
MASTER_SITES=		http://dri.freedesktop.org/libdrm/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bjs@NetBSD.org
HOMEPAGE=		http://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	libdrm.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
##
## NetBSD 2.x and earlier require pthread stubs
## NOTE: This package probably wants the xcb thread stub library.
## What do we do for other platforms?
##
.  include "../../devel/pthread-stublib/buildlink3.mk"
PTHREADSTUBS_LIBS=-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lpthstub
CONFIGURE_ENV+=	PTHREADSTUBS_LIBS=${PTHREADSTUBS_LIBS:Q}
.else
CONFIGURE_ENV+=	PTHREADSTUBS_LIBS=${LDFLAGS:Q}
CONFIGURE_ENV+=	PTHREADSTUBS_CFLAGS=${CFLAGS:Q}
.endif

ATOMIC_OPS_CHECK?=	0

SUBST_CLASSES+=		atomic
SUBST_FILES.atomic=	libdrm/xf86drm.h
SUBST_MESSAGE.atomic=	Configuring xf86drm.h's atomic operations.
SUBST_STAGE.atomic=	pre-configure
SUBST_VARS.atomic=	ATOMIC_OPS_CHECK

.if ${OPSYS} == "NetBSD" && !target(netbsd-atomic-ops-check)
netbsd-atomic-ops-check:
ATOMIC_OPS_CHECK!=\
  if ( ${NM} /usr/lib/libc.so | ${GREP} -q atomic_cas_uint ); then	\
    ${ECHO} "1";	\
  else	\
    ${ECHO} "0";	\
  fi
.endif

.include "../../mk/bsd.pkg.mk"
