# $NetBSD: Makefile,v 1.1.1.1 2006/04/21 04:23:05 jeremy-c-reed Exp $
#

DISTNAME=		xf86dgaproto-2.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86DGA extension headers

PKGCONFIG_OVERRIDE+=	${WRKSRC}/xf86dgaproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
