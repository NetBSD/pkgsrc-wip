# $NetBSD: Makefile,v 1.16 2006/04/12 20:58:16 jeremy-c-reed Exp $
#
 ## this needs to be updated to modular Xorg

DISTNAME=		libXfixes-3.0.1.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xfixes library and extension of X RandR from modular X.org

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xfixes.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/fixesproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
