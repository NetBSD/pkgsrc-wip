# $NetBSD$

DISTNAME=	lxqt-about-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-about/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	LXQt about dialog
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS+=	bin

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
