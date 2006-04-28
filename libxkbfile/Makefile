# $NetBSD: Makefile,v 1.2 2006/04/28 06:29:35 jeremy-c-reed Exp $
#

DISTNAME=		libxkbfile-1.0.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		The xkbfile Library from modular X.org

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xkbfile.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../wip/kbproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
