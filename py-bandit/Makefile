# $NetBSD$

DISTNAME=	bandit-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bandit/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/PyCQA/bandit
COMMENT=	Security oriented static analyser for python code
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-git>=1.0.1:../../wip/py-git
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stevedore>=1.20.0:../../devel/py-stevedore
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

post-install:
.for b in bandit bandit-baseline bandit-config-generator
	${MV} ${DESTDIR}${PREFIX}/bin/${b} \
	    ${DESTDIR}${PREFIX}/bin/${b}${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
