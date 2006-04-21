# $NetBSD: Makefile,v 1.1.1.1 2006/04/21 04:20:15 jeremy-c-reed Exp $
#

DISTNAME=		evieext-1.0.2
# TODO: check if this should be named evieproto to be consistent
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		EvIE extension headers

PKGCONFIG_OVERRIDE+=	${WRKSRC}/evieproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
