# $NetBSD: Makefile,v 1.2 2005/10/17 19:07:27 jeremy-c-reed Exp $
#

DISTNAME=		xf86bigfontproto-1.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86BigFont extension headers from X.org

#CONFLICTS+=		xorg-libs-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xf86bigfontproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
