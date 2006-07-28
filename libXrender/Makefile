# $NetBSD: Makefile,v 1.17 2006/07/28 00:58:35 jeremy-c-reed Exp $
#

DISTNAME=		libXrender-0.9.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Render Library

CONFLICTS+=		Xrender-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xrender.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
