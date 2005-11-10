# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 03:33:38 jeremy-c-reed Exp $
#

DISTNAME=		recordproto-1.13.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Record extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/recordproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
