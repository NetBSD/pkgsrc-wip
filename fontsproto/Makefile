# $NetBSD: Makefile,v 1.1.1.1 2005/10/17 18:34:11 jeremy-c-reed Exp $
#

DISTNAME=		fontsproto-2.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Fonts extension headers from X.org

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fontsproto.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
