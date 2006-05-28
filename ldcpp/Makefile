# $NetBSD: Makefile,v 1.1.1.1 2006/05/28 23:38:59 tnn2 Exp $

DISTNAME=		ldcpp
PKGNAME=		ldcpp-${LDCPP_VERSION}
CATEGORIES=		net x11
MASTER_SITES=		http://linuxdcpp.berlios.de/

MAINTAINER=		tnn+nbsd@nygren.pp.se
HOMEPAGE=		http://linuxdcpp.berlios.de/
COMMENT=		DC++-based p2p filesharing application

CVS_REPOSITORIES=	linuxdcpp
CVS_ROOT.linuxdcpp=	:pserver:anonymous:@cvs.linuxdcpp.berlios.de:/cvsroot/linuxdcpp
CVS_MODULE.linuxdcpp=	linuxdcpp

USE_LANGUAGES=		c c++
GCC_REQD+=		3.4
USE_TOOLS+=		pkg-config

PTHREAD_OPTS+=		native
NO_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
LDCPP_VERSION!=		${DATE} +%Y%m%d
LDFLAGS+=		${X11_LDFLAGS}

post-extract:
	${MV} ${WRKDIR}/linuxdcpp ${WRKSRC}
	${CP} ${FILESDIR}/make.sh ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} ./make.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldcpp ${PREFIX}/bin/ldcpp
	${INSTALL_DATA_DIR} ${PREFIX}/share/ldcpp
	${INSTALL_DATA_DIR} ${PREFIX}/share/ldcpp/glade
	${INSTALL_DATA_DIR} ${PREFIX}/share/ldcpp/pixmaps
	cd ${WRKSRC}/glade && ${PAX} -rw *.glade ${PREFIX}/share/ldcpp/glade
	cd ${WRKSRC}/pixmaps && ${PAX} -rw *.png ${PREFIX}/share/ldcpp/pixmaps

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/compiler.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
