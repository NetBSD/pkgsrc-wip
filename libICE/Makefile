# $NetBSD: Makefile,v 1.19 2006/04/18 18:27:50 jeremy-c-reed Exp $
#

DISTNAME=		libICE-0.99.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC2/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
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
