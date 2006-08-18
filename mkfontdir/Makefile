# $NetBSD: Makefile,v 1.1.1.1 2006/08/18 13:49:35 jeremy-c-reed Exp $
#

DISTNAME=		mkfontdir-1.0.2
CATEGORIES=		fonts x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 font files indexer

# also available with USE_TOOLS+=x11-clients
# but I am using modular
DEPENDS+=		mkfontscale>=1.0.1:../../wip/mkfontscale

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.pkg.mk"
