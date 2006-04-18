# $NetBSD: Makefile,v 1.16 2006/04/18 18:27:51 jeremy-c-reed Exp $
#

DISTNAME=		libXv-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xv Extension library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xv.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/videoproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
