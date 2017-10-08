# $NetBSD$

GITHUB_PROJECT=	coala
DISTNAME=	coala-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=coala/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://coala.io/
COMMENT=	Unified command-line interface for linting and fixing all your code
LICENSE=	gnu-agpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=   27

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-print-[0-9]*:../../wip/py-print
DEPENDS+=	${PYPKGPREFIX}-coala_utils-[0-9]*:../../wip/py-coala_utils

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
