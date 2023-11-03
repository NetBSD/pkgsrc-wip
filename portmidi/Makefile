# $NetBSD$

#GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	portmidi-2.0.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=PortMidi/}

MAINTAINER=	mk@asdfghasdfgh.de
HOMEPAGE=	https://github.com/PortMidi/portmidi/
COMMENT=	Cross Plattform MIDI IO
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	packaging/portmidi.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
