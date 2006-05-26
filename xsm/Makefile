# $NetBSD: Makefile,v 1.1.1.1 2006/05/26 16:09:31 jeremy-c-reed Exp $
#

DISTNAME=		xsm-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/app/
COMMENT=		X Session Manager

GNU_CONFIGURE=		yes
USE_TOOLS+=             pkg-config

#.include "../../wip/libX11/buildlink3.mk"
#.include "../../wip/libXt/buildlink3.mk"

.include "../../mk/xaw.buildlink3.mk"

# maybe just include x11.buildlink3.mk

.include "../../mk/bsd.pkg.mk"
