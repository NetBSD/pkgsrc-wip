# $NetBSD: Makefile,v 1.17 2005/11/12 01:42:32 jeremy-c-reed Exp $
#

DISTNAME=		libXt-0.99.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC2/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Toolkit Intrinsics library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xt.pc.in

.include "../../wip/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/kbproto/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
