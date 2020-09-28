# $NetBSD$


DISTNAME=	brisk-menu-v0.6.2
#PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	x11
MASTER_SITES=	-https://github.com/getsolus/brisk-menu/releases/download/v0.6.2/brisk-menu-v0.6.2.tar.xz

EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getsolus/brisk-menu/
COMMENT=	Modern Menu for MATE-Desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS=	pkg-config
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/brisk-menu-0.6.2
USE_LANGUAGES=	c c++

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${PREFIX}/bin/meson build && \
	${PREFIX}/bin/ninja -C build

.include "../../devel/meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/mate-panel/buildlink3.mk"
.include "../../x11/mate-applets/options.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
