# $NetBSD$

DISTNAME=	SuWidgets-0.1.0git
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=BatchDrake/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	373ab4f976bf983b67a283278d876089a21e575c

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://github.com/BatchDrake/suwidgets/
COMMENT=	Sigutils-related widgets
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	  ${QTDIR}/bin/qmake SuWidgetsLib.pro

.include "../../wip/sigutils/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
