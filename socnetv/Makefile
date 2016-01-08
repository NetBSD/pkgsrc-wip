# $NetBSD$

DISTNAME=	SocNetV-1.9
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=socnetv/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://socnetv.sourceforge.net/index.html
COMMENT=	Social network analysis and visualisation application
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/socnetv-1.9

QMAKE=			${QTDIR}/bin/qmake
USE_TOOLS+=	gzip
USE_LANGUAGES= c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

post-extract:
	gzip -d ${WRKSRC}/man/socnetv.1.gz

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QMAKE} PREFIX=${PREFIX} INSTALLPATH=${PREFIX} socnetv.pro 

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
