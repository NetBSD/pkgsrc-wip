# $NetBSD: Makefile,v 1.20 2006/04/18 18:27:51 jeremy-c-reed Exp $
#

DISTNAME=		libXt-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Toolkit Intrinsics library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1 LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xt.pc.in

.include "../../wip/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/kbproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
