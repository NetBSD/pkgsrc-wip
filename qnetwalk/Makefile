# $NetBSD: Makefile,v 1.1.1.1 2005/01/04 12:21:02 ianzag Exp $
#

DISTNAME=		qnetwalk-1.0
CATEGORIES=		x11 games
MASTER_SITES=	http://qt.osdn.org.ua/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://qt.osdn.org.ua/qnetwalk.html
COMMENT=		QNetwalk is a Qt-version of the popular NetWalk game

# We need qmake to build package's Makefile
BUILD_DEPENDS+=	qt3-tools>=3.*:../../x11/qt3-tools

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

QNETWALK_BIN=	${PREFIX}/bin
QNETWALK_DATA=	${PREFIX}/share/games/${PKGBASE}

# Should we care about Qt3 package paths here ?
do-configure:
	(cd ${WRKSRC} && qmake)

# Fix hardcoded paths
SUBST_CLASSES=		path
SUBST_MESSAGE.path=	"Fixing hardcoded paths."
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	qnetwalk.pro
SUBST_SED.path=		-e 's:@QNETWALK_BIN@:${QNETWALK_BIN}:g'
SUBST_SED.path+=	-e 's:@QNETWALK_DATA@:${QNETWALK_DATA}:g'

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
