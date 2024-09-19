# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:36 thomasklausner Exp $
#

DISTNAME=	v1.3.2
PKGNAME=	heimdall${DISTNAME:S/v/-/1}
CATEGORIES=	comms
MASTER_SITES=	https://github.com/Benjamin-Dobell/Heimdall/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.glassechidna.com.au/products/heimdall/
COMMENT=	Cross-platform OSS suite to flash firmware on Samsung Galaxy S devices
LICENSE=	mit

WRKSRC=			${WRKDIR}/Heimdall-1.3.2
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
QMAKE=			${QTDIR}/bin/qmake
CONFIGURE_DIRS+=	libpit heimdall
BUILD_DIRS+=		libpit heimdall heimdall-frontend
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	heimdall-frontend/Makefile
SUBST_MESSAGE.paths=	Fixing PREFIX and build paths.
SUBST_SED.paths=	-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.paths+=	-e 's|../Linux/heimdall-frontend|./heimdall-frontend|g'
SUBST_STAGE.paths=	post-configure

pre-configure:
	cd ${WRKSRC}/heimdall-frontend && \
		${SETENV} ${CONFIGURE_ENV} ${QMAKE} heimdall-frontend.pro

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
