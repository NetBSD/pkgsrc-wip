# $NetBSD: Makefile,v 1.1.1.1 2006/04/21 04:21:42 jeremy-c-reed Exp $
#

DISTNAME=		trapproto-3.4.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Trap extension headers

PKGCONFIG_OVERRIDE+=	${WRKSRC}/trapproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
