# $NetBSD: Makefile,v 1.2 2007/02/16 13:58:05 tnn2 Exp $

DISTNAME=		linuxdcpp
PKGNAME=		linuxdcpp-${LDCPP_VERSION}
CATEGORIES=		net x11
MASTER_SITES=		http://linuxdcpp.berlios.de/

MAINTAINER=		tnn+nbsd@nygren.pp.se
HOMEPAGE=		http://linuxdcpp.berlios.de/
COMMENT=		DC++-based p2p filesharing application

CONFLICTS+=		ldcpp-*

CVS_REPOSITORIES=	linuxdcpp
CVS_ROOT.linuxdcpp=	:pserver:anonymous:@cvs.linuxdcpp.berlios.de:/cvsroot/linuxdcpp
CVS_MODULE.linuxdcpp=	linuxdcpp

USE_LANGUAGES=		c c++
GCC_REQD+=		3.4
USE_TOOLS+=		pkg-config

PTHREAD_OPTS+=		native
NO_CONFIGURE=		yes
BUILD_DEPENDS+=         scons>=0.96:../../devel/scons

.include "../../mk/bsd.prefs.mk"
LDCPP_VERSION!=		${DATE} +%Y%m%d
LDFLAGS+=		${X11_LDFLAGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons debug=true relase=true PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linuxdcpp ${PREFIX}/bin/linuxdcpp
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxdcpp
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxdcpp/glade
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxdcpp/pixmaps
	cd ${WRKSRC}/glade && ${PAX} -rw *.glade ${PREFIX}/share/linuxdcpp/glade
	cd ${WRKSRC}/pixmaps && ${PAX} -rw *.png ${PREFIX}/share/linuxdcpp/pixmaps

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/compiler.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
