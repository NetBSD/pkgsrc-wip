# $NetBSD$
#

DISTNAME=	OptiBench-0.2.0.9
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	1f6e908da7752237a0d5a56d1d1ab62d8bf1d67e

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/OptiBench
COMMENT=	Benchmark to measure optimal sustained memory and disk performance
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANPREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
