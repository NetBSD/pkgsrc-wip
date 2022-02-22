# $NetBSD: Makefile,v 1.108 2022/01/31 11:43:31 wiz Exp $

DISTNAME=	hypothesmith-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesmith/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Zac-HD/hypothesmith
COMMENT=	Hypothesis strategies for generating Python programs, like CSmith
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-libcst-[0-9]*:../../wip/py-libcst
# XXX: more

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
