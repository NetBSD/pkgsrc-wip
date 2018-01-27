# $NetBSD: Makefile,v 1.1 2015/04/23 09:49:45 ahp-nils Exp $

DISTNAME=	yapf-0.16.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	yapf
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/google/
COMMENT=	Python files formatter
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/yapf ${DESTDIR}${PREFIX}/bin/yapf${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
