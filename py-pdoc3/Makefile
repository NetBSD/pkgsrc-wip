# $NetBSD$

DISTNAME=	pdoc3-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/d9/79/dd3b035c0e3cdfdb972524138b9b6e623dcebbaf787e4e4af7d022b7c09d/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pdoc3.github.io/pdoc/
COMMENT=	Auto-generate API documentation for Python projects
LICENSE=	gnu-agpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.5.0:../../devel/py-setuptools_scm

DEPENDS+=	${PYPKGPREFIX}-mako>=1.1.3:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.1.1:../../textproc/py-markdown

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
