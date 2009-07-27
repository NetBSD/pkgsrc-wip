# $NetBSD: Makefile,v 1.5 2009/07/27 04:01:38 othyro Exp $

DISTNAME=					arora-0.8.0
CATEGORIES=				www net
MASTER_SITES=			http://arora.googlecode.com/files/

MAINTAINER=				zecrazytux@zecrazytux.net
HOMEPAGE=					http://code.google.com/p/arora
COMMENT=					Arora is a simple cross platform web browser using Qt and Webkit

PKG_DESTDIR_SUPPORT=		user-destdir

USE_LIBTOOL=			yes
USE_LANGUAGES=		c++

ARORA_BIN=				../arora

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX} arora.pro)

SUBST_CLASSES+=					path target

SUBST_MESSAGE.path=			Fixing hardcoded man path.
SUBST_STAGE.path=				pre-configure
SUBST_FILES.path=				src/src.pro
SUBST_SED.path=					-e 's:$$$$DATADIR/man:${PREFIX}/${PKGMANDIR}:g'

SUBST_MESSAGE.target=		Fixing target (make install).
SUBST_STAGE.target=			post-build
SUBST_FILES.target=			src/Makefile
SUBST_SED.target=				-e 's,^QMAKE_TARGET.*$$,QMAKE_TARGET=${ARORA_BIN},g'


.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
