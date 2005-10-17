# $NetBSD: Makefile,v 1.2 2005/10/17 19:00:26 jeremy-c-reed Exp $
#

DISTNAME=		inputproto-1.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Input extension headers from X.org

CONFLICTS+=		xextensions-[0-9]*
#CONFLICTS+=		xorg-libs-[0-9]* # not in same PREFIX

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/inputproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
