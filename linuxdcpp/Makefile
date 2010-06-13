# $NetBSD: Makefile,v 1.15 2010/06/13 22:47:10 thomasklausner Exp $

DISTNAME=		linuxdcpp-1.0.3
PKGREVISION=		2
CATEGORIES=		net x11
MASTER_SITES=		http://launchpad.net/linuxdcpp/1.0/1.0.3/+download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		https://launchpad.net/linuxdcpp/
COMMENT=		DC++-based p2p filesharing application

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c c++
GCC_REQD+=		3.4
USE_TOOLS+=		pkg-config pax

PTHREAD_OPTS+=		native
NO_CONFIGURE=		yes
BUILD_DEPENDS+=		scons>=0.96:../../devel/scons

LDFLAGS+=		${X11_LDFLAGS}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "HPUX"
CFLAGS+=		"-Dmadvise(addr,len,behav)="
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons debug=true relase=true PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin share/linuxdcpp/glade share/linuxdcpp/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linuxdcpp \
	  ${DESTDIR}${PREFIX}/bin/linuxdcpp
	cd ${WRKSRC}/glade && pax -rw *.glade \
	  ${DESTDIR}${PREFIX}/share/linuxdcpp/glade
	cd ${WRKSRC}/pixmaps && pax -rw *.png \
	  ${DESTDIR}${PREFIX}/share/linuxdcpp/pixmaps

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
