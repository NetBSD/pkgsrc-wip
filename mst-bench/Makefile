# $NetBSD$
#

DISTNAME=	MST-Bench-0.2.0.13
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	39f2d67f4590bb463f9894b342e42bd79684a425

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/OptiBench
COMMENT=	Benchmark to measure optimal sustained memory and disk performance
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANPREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
