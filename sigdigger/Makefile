# $NetBSD$

DISTNAME=	SigDigger-0.2.0git
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=BatchDrake/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	557f6712d868f2ee08bc38fbbab68d9171f40bfb

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://batchdrake.github.io/SigDigger/
COMMENT=	Graphical digital signal analyzer
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	  ${QTDIR}/bin/qmake SigDigger.pro PREFIX=${PREFIX}

.include "../../wip/suscan/buildlink3.mk"
.include "../../wip/suwidgets/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
