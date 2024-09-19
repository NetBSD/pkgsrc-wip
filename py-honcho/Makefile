# $NetBSD$

DISTNAME=	honcho-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/honcho/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/nickstenning/honcho
COMMENT=	Clone of Foreman, for managing Procfile-based applications
LICENSE=	mit


DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10:../../textproc/py-jinja2

.include "../../lang/python/egg.mk"
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
