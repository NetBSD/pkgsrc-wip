# $NetBSD$

DISTNAME=	repoze.who-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=r/repoze.who/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	http://www.repoze.org/
COMMENT=	Identification and authentication framework for WSGI
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools>=18.5:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
#DEPENDS+=	${PYPKGPREFIX}-repoze.sphinx.autointerface-[0-9]*:../../wip/repoze.sphinx.autointerface


WRKSRC=		${WRKDIR}/repoze.who-2.3
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
