# $NetBSD$

DISTNAME=	lxqt-policykit-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-policykit/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://lxqt.org/
COMMENT=	Policykit authentication agent
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

INSTALLATION_DIRS+=	bin

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools

.include "../../wip/liblxqt/buildlink3.mk"
.include "../../security/polkit-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
