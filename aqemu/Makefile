# $NetBSD$

DISTNAME=	aqemu-0.9.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=tobimensch/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tobimensch/aqemu
COMMENT=	GUI for virtual machines using QEMU as the backend
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	CMakeLists.txt
SUBST_FILES.paths+=	src/main.cpp
SUBST_SED.paths+=	-e "s,/usr/local,${PREFIX},g"
SUBST_SED.paths+=	-e "s,share/man/man1,${PKGMANDIR}/man1,g"

pre-configure:
	${LN} -sf ${QTDIR}/bin/rcc ${TOOLS_DIR}/bin/rcc

.include "../../net/libvncserver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
