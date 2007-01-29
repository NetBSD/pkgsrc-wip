# $NetBSD: Makefile,v 1.1 2007/01/29 08:32:22 bsadewitz Exp $
#

DISTNAME=	listres-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Listres utility from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXaw/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
