# $NetBSD: Makefile,v 1.4 2012/09/24 17:14:36 asau Exp $
#

DISTNAME=	bmp-docklet-1.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://mark.xnull.de/bmp-docklet/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://mark.xnull.de/bmp-docklet.php
COMMENT=		BMP Dock applet


GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		intltool pkg-config
USE_PKGLOCALEDIR=	YES

.include "../../audio/bmp/buildlink3.mk"
# XXX Should we use BUILD_DEPENDS instead?
.include "../../mk/bsd.pkg.mk"
