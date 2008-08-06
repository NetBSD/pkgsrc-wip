# $NetBSD: Makefile,v 1.1.1.1 2008/08/06 05:08:42 phonohawk Exp $
#

DISTNAME=	tome-235-src
PKGNAME=	tome-2.3.5
CATEGORIES=	games
MASTER_SITES=	http://t-o-m-e.net/dl/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://t-o-m-e.net/dl/src/
COMMENT=	Troubles of Middle Earth

BUILD_DIRS=	src
MAKE_FILE=	makefile.std
BUILD_TARGET=	default

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
