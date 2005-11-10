# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 03:50:42 jeremy-c-reed Exp $
#

DISTNAME=		libxkbfile-0.99.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/lib/
COMMENT=		The xkbfile Library from modular X.org

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xkbfile.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../wip/kbproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
