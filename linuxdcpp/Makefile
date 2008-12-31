# $NetBSD: Makefile,v 1.12 2008/12/31 13:18:02 tnn2 Exp $

DISTNAME=		linuxdcpp-1.0.2
CATEGORIES=		net x11
MASTER_SITES=		http://launchpad.net/linuxdcpp/1.0/1.0.2/+download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		https://launchpad.net/linuxdcpp/
COMMENT=		DC++-based p2p filesharing application

USE_LANGUAGES=		c c++
GCC_REQD+=		3.4
USE_TOOLS+=		pkg-config pax

PTHREAD_OPTS+=		native
NO_CONFIGURE=		yes
BUILD_DEPENDS+=		scons>=0.96:../../devel/scons

LDFLAGS+=		${X11_LDFLAGS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "HPUX"
CFLAGS+=		"-Dmadvise(addr,len,behav)="
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons debug=true relase=true PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linuxdcpp ${PREFIX}/bin/linuxdcpp
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxdcpp
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxdcpp/glade
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxdcpp/pixmaps
	cd ${WRKSRC}/glade && pax -rw *.glade ${PREFIX}/share/linuxdcpp/glade
	cd ${WRKSRC}/pixmaps && pax -rw *.png ${PREFIX}/share/linuxdcpp/pixmaps

.include "../../mk/compiler.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
