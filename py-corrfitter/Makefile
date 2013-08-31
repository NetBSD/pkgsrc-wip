# $NetBSD: Makefile,v 1.1 2013/08/31 20:27:22 jihbed Exp $

DISTNAME=	corrfitter-3.6
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/c/corrfitter/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/gplepage/corrfitter.git
COMMENT=	Utilities for fitting correlators in lattice QCD
LICENSE=	gnu-gpl-v3

DEPENDS+=       ${PYPKGPREFIX}-lsqfit>=4.5.1:../../wip/py-lsqfit

FETCH_USING=    curl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X= yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
