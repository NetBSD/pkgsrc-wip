# $NetBSD: Makefile,v 1.15 2006/04/12 20:51:16 jeremy-c-reed Exp $
#

DISTNAME=		libSM-0.99.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC2/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
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
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
