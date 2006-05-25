# $NetBSD: Makefile,v 1.1.1.1 2006/05/25 01:13:11 jeremy-c-reed Exp $
#

DISTNAME=		mkfontscale-1.0.1
CATEGORIES=		fonts x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Scalable font files indexer for X11

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../wip/libfontenc/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
