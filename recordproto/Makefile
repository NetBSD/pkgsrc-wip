# $NetBSD: Makefile,v 1.2 2006/04/28 06:29:35 jeremy-c-reed Exp $
#

DISTNAME=		recordproto-1.13.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Record extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/recordproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
