# $NetBSD$
#

DISTNAME=	OptiBench-0.2.0.1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	287978199ac7c5b5c65f82f75a8032dad8d4239d

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/OptiBench
COMMENT=	Benchmark to measure optimal sustained memory and disk performance
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANPREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
