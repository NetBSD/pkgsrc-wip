# $NetBSD: Makefile,v 1.5 2003/05/07 22:18:22 lsed Exp $
#

DISTNAME=	celestia-1.3.0
CATEGORIES=	misc x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=celestia/}

MAINTAINER=	cesar_catrian@yahoo.com
HOMEPAGE=	http://www.shatters.net/celestia/
COMMENT=	Free real-time 3D space simulator

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include
CONFIGURE_ARGS+=	--with-lua=${BUILDLINK_PREFIX.lua}
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-kde

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../lang/lua/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
