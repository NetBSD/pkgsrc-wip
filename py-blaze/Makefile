# $NetBSD: Makefile,v 1.1 2014/10/04 08:22:34 jihbed Exp $

DISTNAME=	blaze-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blaze/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://blaze.pydata.org/docs/latest/index.html
COMMENT=	NumPy and Pandas interface to Big Data
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.14.1:../../math/py-pandas

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
