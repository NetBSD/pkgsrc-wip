# $NetBSD$

#GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	portaudio-19.7.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=PortAudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PortAudio/portaudio/
COMMENT=	TODO: Short description of the package
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	bindings/cpp/portaudiocpp.pc.in
PKGCONFIG_OVERRIDE+=	cmake_support/portaudio-2.0.pc.in
PKGCONFIG_OVERRIDE+=	portaudio-2.0.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
