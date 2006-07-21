# $NetBSD: Makefile,v 1.20 2006/07/21 01:59:41 jeremy-c-reed Exp $
#
 ## this needs to be updated to modular Xorg

DISTNAME=		libXfixes-3.0.1.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xfixes library and extension of X RandR from modular X.org

CONFLICTS+=		Xfixes-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xfixes.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
