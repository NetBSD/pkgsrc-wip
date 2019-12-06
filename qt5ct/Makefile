# $NetBSD$

DISTNAME=		qt5ct-0.41
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qt5ct/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		voidpin@protonmail.com
HOMEPAGE=		https://sourceforge.net/projects/qt5ct/files/
COMMENT=		Tool for customizing Qt5-apps outside KDE
LICENSE=		2-clause-bsd

USE_TOOLS=		pkg-config
USE_LANGUAGES=		c c++

WRKSRC=         	${WRKDIR}/${DISTNAME}

QTDIR=			/usr/pkg/qt5
MAKE_ENV+=		QTPREFIX=${QTDIR}
QMAKE=			${QTPREFIX}/bin/qmake
CONFIGURE_ENV+=		QMAKE=${QMAKE}
CONFIGURE_ARGS+= 	QMAKE

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile)

TOOL_DEPENDS+=		qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
