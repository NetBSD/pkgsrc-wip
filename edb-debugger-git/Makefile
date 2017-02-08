# $NetBSD$

DISTNAME=	edb-debugger-0.9.21
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=eteran/}

#WRKSRC=		${WRKDIR}/debugger

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codef00.com/projects#debugger
COMMENT=	Cross platform x86/x86-64 debugger
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

#do-configure:
#	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake -makefile DEFAULT_PLUGIN_PATH="${PREFIX}/lib/${PKGBASE}/"
#
#.include "../../devel/boost-headers/buildlink3.mk"
#.include "../../x11/qt4-libs/buildlink3.mk"
#.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
