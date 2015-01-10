# $NetBSD: Makefile,v 1.1 2015/01/10 09:41:22 thomasklausner Exp $

DISTNAME=	libbpg-0.9.4
CATEGORIES=	graphics
MASTER_SITES=	http://bellard.org/bpg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bellard.org/bpg/
COMMENT=	Library for BGP (Better Portable Graphics)
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
INSTALLATION_DIRS=	bin

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
