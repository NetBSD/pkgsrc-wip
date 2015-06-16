# $NetBSD: Makefile,v 1.1 2015/06/16 09:32:26 ahp-nils Exp $

DISTNAME=	cookiecutter-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/audreyr/cookiecutter/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}
EXTRACT_SUFX=	.zip

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/audreyr/cookiecutter/
COMMENT=	Command-line utility that creates projects from project templates
LICENSE=	modified-bsd

USE_LANGUAGES=	#none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_ACCEPTED=	34 33 27

DEPENDS+=	${PYPKGPREFIX}-binaryornot>=0.2.0:../../wip/py-binaryornot
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-click<4.0:../../devel/py-click
# for python < 3.0
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	cookiecutter/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
