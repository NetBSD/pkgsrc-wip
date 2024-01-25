# $NetBSD: Makefile,v 1.21 2023/11/12 13:21:42 wiz Exp $

DISTNAME=	q5go-2.1.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=bernds/}
GITHUB_PROJECT=	q5Go
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bernds/q5Go/
COMMENT=	Tool for Go players
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	build

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-configure
SUBST_FILES.dirs=	templates/qgo.desktop
SUBST_VARS.dirs+=	PREFIX

do-configure:
	${MKDIR} ${WRKSRC}/build
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake ../src/q5go.pro PREFIX=${PREFIX}

post-install:
	${QTDIR}/bin/qmake -install qinstall "${WRKSRC}/src/images/Bowl.ico" "${DESTDIR}${PREFIX}/share/q5go/pics/Bowl.ico"
	${QTDIR}/bin/qmake -install qinstall "${WRKSRC}/templates/qgo.desktop" "${DESTDIR}${PREFIX}/share/applications/q5go.desktop"

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
