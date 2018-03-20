# $NetBSD$

DISTNAME=	dtc-1.4.4
CATEGORIES=	devel
MASTER_SITES=	https://www.kernel.org/pub/software/utils/dtc/

MAINTAINER=	joe.davis512@gmail.com
HOMEPAGE=	http://devicetree.org/
COMMENT=	Device Tree Compiler (dtc)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake bison

MAKE_FLAGS+=	PREFIX=${PREFIX}

REPLACE_BASH+=	dtdiff
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
