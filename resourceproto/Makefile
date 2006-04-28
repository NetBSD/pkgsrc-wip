# $NetBSD: Makefile,v 1.2 2006/04/28 06:29:36 jeremy-c-reed Exp $
#

DISTNAME=		resourceproto-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Resource extension headers from X.org

CONFLICTS+=		resourceext-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/resourceproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
