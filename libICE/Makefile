# $NetBSD: Makefile,v 1.21 2006/05/19 16:51:20 ykomatsu Exp $
#

DISTNAME=		libICE-1.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Inter Client Exchange (ICE) library for X

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	ice.pc.in

.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
