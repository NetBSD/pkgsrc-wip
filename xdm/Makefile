# $NetBSD: Makefile,v 1.1 2007/01/29 07:55:41 bsadewitz Exp $
#

DISTNAME=	xdm-1.1.3
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/release/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X Display Manager from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

.include "../../x11/libXaw/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
