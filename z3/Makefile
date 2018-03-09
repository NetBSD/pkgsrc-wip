# $NetBSD: Makefile,v 1.7 2018/02/27 08:34:16 wiz Exp $

DISTNAME=	z3-4.5.0
GITHUB_TAG=	${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Z3Prover/}

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	https://github.com/Z3Prover/z3/
COMMENT=	The Z3 theorem prover / SMT solver
LICENSE=	mit

WRKSRC=		${WRKDIR}/z3-${DISTNAME}
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
BUILD_DIRS=	build

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
CONFIGURE_ARGS+=	--destdir=${DESTDIR} --prefix=${PREFIX}

.include "options.mk"

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
