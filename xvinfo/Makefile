# $NetBSD: Makefile,v 1.3 2007/03/28 18:11:02 bsadewitz Exp $
#

DISTNAME=	xvinfo-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Xv info utility from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
