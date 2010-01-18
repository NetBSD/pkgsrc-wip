# $NetBSD: Makefile,v 1.8 2010/01/18 09:38:17 thomasklausner Exp $

DISTNAME=		arora-0.9.0
PKGREVISION=		1
CATEGORIES=		www net
MASTER_SITES=		http://arora.googlecode.com/files/

MAINTAINER=		zecrazytux@zecrazytux.net
HOMEPAGE=		http://code.google.com/p/arora
COMMENT=		Arora is a web browser using Qt and Webkit
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

USE_LIBTOOL=		yes
USE_LANGUAGES=		c++

CHECK_PORTABILITY_SKIP=	autotests/runTests.sh

ARORA_BIN=		../arora

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX} arora.pro)

SUBST_CLASSES+=		path target

SUBST_MESSAGE.path=	Fixing hardcoded man path.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	src/src.pro tools/cacheinfo/cacheinfo.pro \
			tools/htmlToXBel/htmlToXBel.pro \
			tools/placesimport/placesimport.pro
SUBST_SED.path=		-e 's:$$$$DATADIR/man:${PREFIX}/${PKGMANDIR}:g'

SUBST_MESSAGE.target=	Fixing target (make install).
SUBST_STAGE.target=	post-build
SUBST_FILES.target=	src/Makefile
SUBST_SED.target=	-e 's,^QMAKE_TARGET.*$$,QMAKE_TARGET=${ARORA_BIN},g'

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
