# $NetBSD: Makefile,v 1.1 2007/01/23 13:33:08 bsadewitz Exp $
#

DISTNAME=	appres-1.0.1
CATEGORIES=	wip
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org X resources applet

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config


.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
