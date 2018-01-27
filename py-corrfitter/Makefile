# $NetBSD: Makefile,v 1.3 2014/05/12 22:21:49 jihbed Exp $

DISTNAME=	corrfitter-3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/corrfitter/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/gplepage/corrfitter.git
COMMENT=	Utilities for fitting correlators in lattice QCD
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-lsqfit>=4.8:../../wip/py-lsqfit

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
