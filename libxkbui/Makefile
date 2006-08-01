# $NetBSD: Makefile,v 1.2 2006/08/01 23:37:16 jeremy-c-reed Exp $
#

DISTNAME=		libxkbui-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		INSERT_YOUR_MAIL_ADDRESS_HERE
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
