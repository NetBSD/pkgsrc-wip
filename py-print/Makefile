# $NetBSD$

GITHUB_PROJECT=	PyPrint
DISTNAME=	PyPrint-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=coala/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/coala/PyPrint/
COMMENT=	Simple printer library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-termcolor-[0-9]*:../../wip/py-termcolor

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
