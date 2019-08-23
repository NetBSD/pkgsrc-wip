# $NetBSD$

DISTNAME=	adplay-1.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=adplug/}
GITHUB_PROJECT=	adplay-unix
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/adplug/adplay-unix
COMMENT=	Console-based OPL2 audio player
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS=	--disable-output-ao \
		--disable-output-esound \
		--disable-output-alsa \
		--disable-output-sdl

LDFLAGS+=	-lossaudio

.include "../../audio/adplug/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
