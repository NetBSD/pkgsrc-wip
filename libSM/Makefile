# $NetBSD: Makefile,v 1.18 2006/05/19 16:51:21 ykomatsu Exp $
#

DISTNAME=		libSM-1.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Session Management Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	sm.pc.in

# XXX it is based on how libX11 was built ?
#.include "../../mk/pthread.buildlink3.mk"

.include "../../wip/libICE/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
