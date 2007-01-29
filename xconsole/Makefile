# $NetBSD: Makefile,v 1.2 2007/01/29 09:41:26 absd Exp $
#

DISTNAME=	xconsole-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
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
