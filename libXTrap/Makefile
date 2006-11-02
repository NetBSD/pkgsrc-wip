# $NetBSD: Makefile,v 1.1.1.1 2006/11/02 11:16:13 jsonn Exp $
#

DISTNAME=		libXTrap-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Trap Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xtrap.pc.in

.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/trapproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
