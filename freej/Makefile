# $NetBSD: Makefile,v 1.11 2012/12/04 01:57:59 othyro Exp $
#

DISTNAME=	freej-0.10
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.dyne.org/freej/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freej.dyne.org/
COMMENT=	Instrument for realtime video manipulation
LICENSE=	gnu-gpl-v3

NOT_FOR_PLATFORM=	NetBSD-*-*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../audio/libshout/buildlink3.mk"
.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
