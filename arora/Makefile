# $NetBSD: Makefile,v 1.1.1.1 2009/03/05 01:03:07 zecrazytux Exp $
#

DISTNAME=	arora-0.5
CATEGORIES=	www net
MASTER_SITES=	http://arora.googlecode.com/files/

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://code.google.com/p/arora
COMMENT=	Arora is a simple cross platform web browser using Qt and Webkit

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LANGUAGES=	c++
USE_DIRS+=	xdg-1.4

ARORA_BIN=	../arora

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX} arora.pro)

SUBST_CLASSES+=         path target

SUBST_MESSAGE.path=     Fixing hardcoded man path.
SUBST_STAGE.path=       pre-configure
SUBST_FILES.path=       src/src.pro
SUBST_SED.path=         -e 's:$$$$DATADIR/man:${PREFIX}/${PKGMANDIR}:g'

SUBST_MESSAGE.target=     Fixing target (make install).
SUBST_STAGE.target=       post-build
SUBST_FILES.target=       src/Makefile
SUBST_SED.target=         -e 's,^QMAKE_TARGET.*$$,QMAKE_TARGET=${ARORA_BIN},g'



.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
