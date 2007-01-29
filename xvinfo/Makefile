# $NetBSD: Makefile,v 1.1 2007/01/29 08:04:34 bsadewitz Exp $
#

DISTNAME=	xvinfo-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	Xv info utility from modular X.org

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
