# $NetBSD: Makefile,v 1.10 2012/11/25 23:32:13 othyro Exp $
#

DISTNAME=		freej-0.8.1
PKGREVISION=		4
CATEGORIES=		multimedia
MASTER_SITES=		http://www.ljudmila.org/~jaromil/freej/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://freej.dyne.org/
COMMENT=		Instrument for realtime video manipulation

PKG_DESTDIR_SUPPORT=    none

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
