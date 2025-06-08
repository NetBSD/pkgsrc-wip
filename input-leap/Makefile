# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	input-leap-3.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=input-leap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/input-leap/input-leap/
COMMENT=	Open-source KVM software
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# Should this be an option?
# * net/deskflow provides compatibility and a GUI
# * building without Qt makes this package feasible for
#   constrained hardware
CMAKE_CONFIGURE_ARGS+=	-DINPUTLEAP_BUILD_GUI=OFF
CMAKE_CONFIGURE_ARGS+=	-DINPUTLEAP_USE_EXTERNAL_GTEST=ON

INSTALLATION_DIRS+=	share/examples/input-leap

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/input-leap.conf.example* ${DESTDIR}${PREFIX}/share/examples/input-leap/

.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
