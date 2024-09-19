# $NetBSD$

DISTNAME=	flask_simplelogin-0.0.7
PKGNAME=	${PYPKGPREFIX}-flask-simplelogin-0.0.7
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/23/fb/732df9ec0725c35d7759d797428c768992ad8ba7c906595d02330b42735c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/cuducos/flask_simplelogin/
COMMENT=	Flask Simple Login - Login Extension for Flask
LICENSE=	mit


DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=0.14.3:../../www/py-flask-wtf

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
