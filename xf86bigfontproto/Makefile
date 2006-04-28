# $NetBSD: Makefile,v 1.3 2006/04/28 06:29:36 jeremy-c-reed Exp $
#

DISTNAME=		xf86bigfontproto-1.1.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86BigFont extension headers from X.org

#CONFLICTS+=		xorg-libs-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xf86bigfontproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
