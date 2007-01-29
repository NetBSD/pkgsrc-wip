# $NetBSD: Makefile,v 1.1 2007/01/29 08:12:03 bsadewitz Exp $
#

DISTNAME=	ico-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	Polyhedron animation program from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config
PTHREAD_AUTO_VARS=	yes

.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
