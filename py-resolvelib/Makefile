# $NetBSD: Makefile,v 1.45 2020/12/18 09:03:43 adam Exp $

DISTNAME=	resolvelib-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/resolvelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sarugaku/resolvelib
COMMENT=	Resolve abstract dependencies into concrete ones
LICENSE=	isc

USE_LANGUAGES=	# none

post-install:
	${CHMOD} -R go-w ${DESTDIR}${PREFIX}/${PYSITELIB}/resolvelib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
