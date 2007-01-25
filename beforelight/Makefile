# $NetBSD: Makefile,v 1.3 2007/01/25 16:15:14 bsadewitz Exp $
#

DISTNAME=	beforelight-1.0.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Beforelight screensaver from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
