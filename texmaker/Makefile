# $NetBSD: Makefile,v 1.9 2014/01/04 19:19:46 nros Exp $

DISTNAME=	texmaker-4.1.1
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xm1math.net/texmaker/
COMMENT=	LaTeX editor and front end
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++ c
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake PREFIX=${PREFIX} texmaker.pro DESKTOPDIR=${PREFIX}/share/applications ICONDIR=${PREFIX}/share/pixmaps

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../wip/poppler-qt5/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
