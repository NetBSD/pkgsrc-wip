# $NetBSD: Makefile,v 1.2 2005/11/14 18:30:53 jeremy-c-reed Exp $
#

DISTNAME=		libfontenc-0.99.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		The fontenc Library from X.org

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fontenc.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
