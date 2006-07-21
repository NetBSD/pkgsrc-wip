# $NetBSD: Makefile,v 1.17 2006/07/21 02:01:37 jeremy-c-reed Exp $
#

DISTNAME=		libXfont-1.1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X font Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xfont.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk" ## configure doesn't check for this
.include "../../wip/fontcacheproto/buildlink3.mk"
.include "../../wip/libfontenc/buildlink3.mk"
.include "../../wip/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
