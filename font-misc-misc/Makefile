# $NetBSD: Makefile,v 1.2 2006/10/05 13:59:37 rillig Exp $
#

DISTNAME=		font-misc-misc-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/font/
COMMENT=		Standard X11 "fixed" PCF font

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

# build depends on mkfontscale
# and mkfontdir
# build depends on bdftopcf which is part of x11-clients USE_TOOLS,
# but I will use the modular Xorg instead

.include "../../wip/font-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
