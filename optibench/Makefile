# $NetBSD$
#

DISTNAME=	OptiBench-0.2.0.8
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	35a48f7aa7ff4f4729f06fd6d2c170564933d4c5

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/OptiBench
COMMENT=	Benchmark to measure optimal sustained memory and disk performance
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANPREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
