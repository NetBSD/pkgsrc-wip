# $NetBSD: Makefile,v 1.4 2006/04/28 06:29:35 jeremy-c-reed Exp $
#

DISTNAME=		libXdmcp-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Display Manager Control Protocol library from X.org

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xdmcp.pc.in
GNU_CONFIGURE=		yes

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
