# $NetBSD: Makefile,v 1.4 2005/05/02 13:51:19 cetrox Exp $
#

DISTNAME=		fox-1.2.16
CATEGORIES=		x11
MASTER_SITES=		http://www.fox-toolkit.org/ftp/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.fox-toolkit.org/
COMMENT=		Fast and extensive C++ GUI toolkit

CONFIGURE_ARGS+=	--disable-opengl	\
			--disable-static	\
			--enable-release

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
