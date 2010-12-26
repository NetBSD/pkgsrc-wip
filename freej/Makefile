# $NetBSD: Makefile,v 1.6 2010/12/26 05:01:22 davesainty Exp $
#

DISTNAME=		freej-0.8.1
PKGREVISION=		3
CATEGORIES=		multimedia
MASTER_SITES=		http://www.ljudmila.org/~jaromil/freej/releases/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://freej.dyne.org/
COMMENT=		Instrument for realtime video manipulation

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../wip/alsa-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
