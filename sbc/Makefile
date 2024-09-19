# $NetBSD$

DISTNAME=	sbc-1.4
CATEGORIES=	audio
MASTER_SITES=	https://mirrors.edge.kernel.org/pub/linux/bluetooth/

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://en.wikipedia.org/wiki/SBC_(codec) # no own page
COMMENT=	Bluetooth subband codec
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tester

.include "../../mk/bsd.pkg.mk"
