# $NetBSD: Makefile,v 1.1.1.1 2009/03/05 17:10:59 phonohawk Exp $
#

DISTNAME=		libAppleWM-1.2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pho@cielonegro.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X.org libAppleWM library

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	applewm.pc.in
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/applewmproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
