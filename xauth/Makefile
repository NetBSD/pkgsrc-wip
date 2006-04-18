# $NetBSD: Makefile,v 1.2 2006/04/18 18:27:51 jeremy-c-reed Exp $
#

DISTNAME=		xauth-1.0.1
CATEGORIES=		x11 security
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X authority file utility (from X.org)

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
