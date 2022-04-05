# $NetBSD$

DISTNAME=	astroalign-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroalign/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://astroalign.readthedocs.io/en/latest/
COMMENT=	Python module for aligning astronomical images
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools>=50.3.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
