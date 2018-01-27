# $NetBSD: Makefile,v 1.1 2015/08/01 22:32:33 jihbed Exp $

DISTNAME=	nilearn-0.1.4.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nilearn/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://nilearn.github.io
COMMENT=	Statistical learning for neuroimaging in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-nibabel>=1.3.0:../../wip/py-nibabel
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.15.2:../../math/py-scikit-learn

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
