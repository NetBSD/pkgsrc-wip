# $NetBSD: Makefile,v 1.1 2005/11/19 11:37:20 ianzag Exp $
#

DISTNAME=		bmp-docklet-1.3
CATEGORIES=		audio
MASTER_SITES=	http://mark.xnull.de/bmp-docklet/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://mark.xnull.de/bmp-docklet.php
COMMENT=		BMP Dock applet

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=			pkg-config
USE_PKGLOCALEDIR=	YES

.include "../../audio/bmp/buildlink3.mk"
# XXX Should we use BUILD_DEPENDS instead?
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
