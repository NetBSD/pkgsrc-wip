# $NetBSD: Makefile,v 1.1 2007/01/29 07:08:53 bsadewitz Exp $
#

DISTNAME=	xconsole-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/release/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Xconsole utility from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c


.include "../../x11/libXaw/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
