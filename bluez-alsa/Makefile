# $NetBSD$

DISTNAME=	bluez-alsa-2.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Arkq/}
GITHUB_TAG=	v2.0.0

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://github.com/Arkq/bluez-alsa
COMMENT=	Stream audio from/to a Bluetooth device
LICENSE=	mit

ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		autoconf automake pkg-config
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../wip/bluez/buildlink3.mk"
.include "../../wip/sbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
