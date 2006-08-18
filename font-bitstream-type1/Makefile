# $NetBSD: Makefile,v 1.1.1.1 2006/08/18 13:51:59 jeremy-c-reed Exp $
#

DISTNAME=		font-bitstream-type1-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/font/
COMMENT=		Bitstream Charter and Courier Type 1 outline fonts

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

# install depends on mkfontscale and mkfontdir and fc-cache (fontconfig)
# I have mkfontscale and mkfontdir in pkgsrc-wip
# but maybe USE_TOOLS+=x11-clients will work too

.include "../../mk/bsd.pkg.mk"
