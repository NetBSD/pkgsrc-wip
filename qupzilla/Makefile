# $NetBSD: Makefile,v 1.2 2014/02/18 18:34:18 nros Exp $

DISTNAME=	QupZilla-1.6.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	http://qupzilla.com/uploads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qupzilla.com/
COMMENT=	Crossplatform QTWebkit based web browser
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
MAKE_ENV+=	QUPZILLA_PREFIX=${PREFIX}/
MAKE_ENV+=	DISABLE_DBUS=${TRUE}

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
	env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

post-install:
	libtool --silent --mode=install \
 	${INSTALL_PROGRAM} ${WRKSRC}/bin/qupzilla \
	${DESTDIR}${PREFIX}/bin

DEPENDS+=qt4-sqlite3>=4.7:../../x11/qt4-sqlite3

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
