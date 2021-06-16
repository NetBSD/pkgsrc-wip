# $NetBSD$
#

DISTNAME=	OptiBench-0.2.0.11
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	d8f4cb125d3afee8d834debb91e9a1dfc614b168

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/OptiBench
COMMENT=	Benchmark to measure optimal sustained memory and disk performance
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANPREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
