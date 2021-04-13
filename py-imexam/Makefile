# $NetBSD$

DISTNAME=	imexam-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/imexam/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/imexam/
COMMENT=	Python module for astronomical image examination
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-photutils>=1.0.1:../../math/py-photutils
DEPENDS+=	${PYPKGPREFIX}-ginga>=3.1.0:../../wip/py-ginga

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
