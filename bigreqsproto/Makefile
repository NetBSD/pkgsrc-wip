# $NetBSD: Makefile,v 1.1.1.1 2005/08/07 05:36:05 jeremy-c-reed Exp $
#

DISTNAME=		bigreqsproto-1.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		BigReqs extension headers from modular Xorg X11

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/bigreqsproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
