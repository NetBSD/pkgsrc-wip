# $NetBSD: Makefile,v 1.6 2012/10/07 16:23:16 asau Exp $

DISTNAME=	spandsp-0.0.6pre12
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	x400@msfu.ru
HOMEPAGE=	http://www.soft-switch.org/
COMMENT=	DSP functions

PKG_DESTDIR_SUPPORT=	none

WRKSRC=		${WRKDIR}/spandsp-0.0.6
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran77
USE_TOOLS+=	gmake

.include "options.mk"

BUILDLINK_API_DEPENDS.tiff+=   tiff>=3.6.1

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
