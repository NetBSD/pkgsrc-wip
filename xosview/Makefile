# $NetBSD: Makefile,v 1.1 2015/05/03 18:48:58 bsiegert Exp $

DISTNAME=	xosview-1.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pogo.org.uk/~mark/xosview/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pogo.org.uk/~mark/xosview/
COMMENT=	X11 graphical display of OS statistics

USE_X11BASE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
BUILD_TARGET=	xosview

# FIXME
MAKE_FLAGS+=	PLATFORM=bsd

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	PREFIX_TO_USE=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if !defined(UVM) && exists(/usr/include/uvm/uvm.h)
CFLAGS+=	-DUVM
UVM=		yes
BUILD_DEFS+=	UVM
.  endif
.elif ${OPSYS} == "SunOS"
CPPFLAGS+=	-I${X11BASE}/include
LIBS+=		-lsocket -lnsl
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "OpenBSD" || ${OPSYS} == "MirBSD" || \
    ${OPSYS} == "DragonFly"
SPECIAL_PERMS+=	bin/xosview ${REAL_ROOT_USER} kmem 2555
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_MESSAGE.paths=	Fixing manpage path.
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e s,share/man/man1,${PKGMANDIR}/man1,

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
