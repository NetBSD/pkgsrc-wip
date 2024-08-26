# $NetBSD$

DISTNAME=	cudd-3.0.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=davidkebo/cudd/blob/main/cudd_versions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidkebo/cudd/blob/main/cudd_versions/
COMMENT=	Package for the manipulation of Binary Decision Diagrams (BDDs), etc
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	autoconf automake autoreconf
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
