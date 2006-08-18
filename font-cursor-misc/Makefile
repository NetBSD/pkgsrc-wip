# $NetBSD: Makefile,v 1.1.1.1 2006/08/18 13:55:29 jeremy-c-reed Exp $
#

DISTNAME=		font-cursor-misc-1.0.0
CATEGORIES=		fonts x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/font/
COMMENT=		Standard X11 cursors in PCF format

GNU_CONFIGURE=		yes

# install depends on mkfontscale and mkfontdir
# build depends on bdftopcf which is part of x11-clients USE_TOOLS,
# but I will use the modular Xorg instead

.include "../../mk/bsd.pkg.mk"
