# $NetBSD: Makefile,v 1.1.1.1 2005/10/17 18:40:44 jeremy-c-reed Exp $
#

DISTNAME=		libfontenc-0.99.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		The fontenc Library from X.org

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fontenc.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
