# $NetBSD: Makefile,v 1.1.1.1 2005/08/08 18:56:13 larnor Exp $
#

DISTNAME=		kbproto-1.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		TBD

CONFLICTS+=		xextensions-[0-9]*
CONFLICTS+=		xorg-libs-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/kbproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
