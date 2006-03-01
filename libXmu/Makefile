# $NetBSD: Makefile,v 1.17 2006/03/01 23:56:04 jeremy-c-reed Exp $
#

DISTNAME=		libXmu-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Miscellaneous Utilities library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xmu.pc.in
PKGCONFIG_OVERRIDE+=	xmuu.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

#.include "../../wip/libICE/buildlink3.mk"
#.include "../../wip/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"
.include "../../wip/xextproto/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
