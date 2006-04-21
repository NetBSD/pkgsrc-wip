# $NetBSD: Makefile,v 1.1.1.1 2006/04/21 04:24:13 jeremy-c-reed Exp $
#

DISTNAME=		glproto-1.4.6
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		GL extension headers

PKGCONFIG_OVERRIDE+=	${WRKSRC}/glproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
