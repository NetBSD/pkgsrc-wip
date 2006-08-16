# $NetBSD: Makefile,v 1.2 2006/08/16 13:52:17 ghen Exp $
#

DISTNAME=		trapproto-3.4.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Trap extension headers

PKGCONFIG_OVERRIDE+=	${WRKSRC}/trapproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
