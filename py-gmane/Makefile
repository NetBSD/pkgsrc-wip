# $NetBSD: Makefile,v 1.1 2015/08/05 20:40:34 jihbed Exp $

DISTNAME=	gmane-0.1.dev25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gmane/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ttm/gmane
COMMENT=	Utilities for the analysis of the GMANE email list database
LICENSE=	public-domain

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.4.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=1.1.2:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
