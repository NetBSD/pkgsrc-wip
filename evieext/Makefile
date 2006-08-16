# $NetBSD: Makefile,v 1.2 2006/08/16 13:52:17 ghen Exp $
#

DISTNAME=		evieext-1.0.2
# TODO: check if this should be named evieproto to be consistent
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		EvIE extension headers

PKGCONFIG_OVERRIDE+=	${WRKSRC}/evieproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
