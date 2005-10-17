# $NetBSD: Makefile,v 1.13 2005/10/17 19:25:33 jeremy-c-reed Exp $
#

DISTNAME=		libXfont-0.99.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X font Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xfont.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk" ## configure doesn't check for this
.include "../../wip/fontcacheproto/buildlink3.mk"
.include "../../wip/libfontenc/buildlink3.mk"
.include "../../wip/fontsproto/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
