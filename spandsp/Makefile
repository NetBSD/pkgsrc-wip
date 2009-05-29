# $NetBSD: Makefile,v 1.2 2009/05/29 12:21:11 x400 Exp $

DISTNAME=	spandsp-0.0.6pre7
CATEGORIES=	devel
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	x400@msfu.ru
HOMEPAGE=	http://www.soft-switch.org/
COMMENT=	DSP functions

WRKSRC=		${WRKDIR}/spandsp-0.0.6
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran
USE_TOOLS+=	gmake

.include "options.mk"

BUILDLINK_API_DEPENDS.tiff+=   tiff>=3.6.1

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
