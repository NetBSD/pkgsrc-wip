# $NetBSD$

DISTNAME=	fswebcam-20140113
CATEGORIES=	graphics www
MASTER_SITES=	https://www.sanslogic.co.uk/fswebcam/files/

MAINTAINER=	catskillmarina@gmail.com
HOMEPAGE=	https://www.sanslogic.co.uk/fswebcam/
COMMENT=	Pulls single images off of webcams without graphic bloat
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-v4l1

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
