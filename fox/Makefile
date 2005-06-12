# $NetBSD: Makefile,v 1.6 2005/06/12 23:51:18 kristerw Exp $
#

DISTNAME=		fox-1.2.16
PKGREVISION=		1
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
GNU_CONFIGURE=		yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
