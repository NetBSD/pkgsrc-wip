# $NetBSD: Makefile,v 1.3 2006/08/16 13:52:17 ghen Exp $
#

DISTNAME=		libxkbui-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		xkbui library

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xkbui.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"
.include "../../wip/libxkbfile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
