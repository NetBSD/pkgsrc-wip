# $NetBSD: Makefile,v 1.4 2007/03/28 18:21:56 bsadewitz Exp $
#

DISTNAME=	editres-1.0.3
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	The modular X.org resource editor

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXaw/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
