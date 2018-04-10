# $NetBSD: Makefile,v 1.1 2014/08/12 21:36:43 thomasklausner Exp $

DISTNAME=	cool-old-term-0.0.201408
CATEGORIES=	x11
MASTER_SITES=	https://github.com/Swordifish90/cool-old-term

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Swordifish90/cool-old-term
COMMENT=	Good looking terminal emulator which mimics the old cathode display
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	cool-old-term
GIT_REPO.cool-old-term=	git://github.com/Swordifish90/cool-old-term.git
WRKSRC=			${WRKDIR}/cool-old-term

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

BUILD_DIRS=		konsole-qml-plugin
USE_LANGUAGES=		c c++
USE_TOOLS+=		pax
MAKE_FLAGS+=		INSTALL_ROOT=${DESTDIR}${PREFIX}/lib/cool-old-term/import
INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC}/${BUILD_DIRS} && ${QTDIR}/bin/qmake

post-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/cool-old-term
	${ECHO} 'QT_QPA_PLATFORMTHEME=' >> ${WRKSRC}/cool-old-term
	${ECHO} "${QTDIR}/bin/qmlscene -I ${PREFIX}/lib/cool-old-term/import ${PREFIX}/lib/cool-old-term/app/main.qml "'"$$@"' >> ${WRKSRC}/cool-old-term

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cool-old-term ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -pp -rw app ${DESTDIR}${PREFIX}/lib/cool-old-term

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
