# $NetBSD$

DISTNAME=	qodem-1.0.0
CATEGORIES=	comms
MASTER_SITES=	https://downloads.sourceforge.net/project/qodem/qodem/1.0.0/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	http://qodem.sourceforge.net/
COMMENT=	Re-implementation of the DOS-era Qmodem serial communications package
LICENSE=	cc0-1.0-universal

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-sdl --disable-upnp

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
