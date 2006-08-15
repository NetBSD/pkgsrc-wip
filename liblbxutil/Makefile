# $NetBSD: Makefile,v 1.3 2006/08/15 14:54:32 jeremy-c-reed Exp $
#

DISTNAME=		liblbxutil-1.0.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Low-Bandwidth X (LBX) utilities library

#USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/lbxutil.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
