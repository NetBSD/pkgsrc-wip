# $NetBSD: Makefile,v 1.1.1.1 2004/03/27 15:14:34 shattered Exp $
#

DISTNAME=	libmatroska-0.6.3
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix="${PREFIX}"
BUILD_DIRS=	${WRKDIR}/${DISTNAME}/make/linux

.include "../../wip/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
