# $NetBSD$

DISTNAME=	wasanbon-1.0.0.post9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.post9//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wasanbon/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.sugarsweetrobotics.com/
COMMENT=	Development Framework for Robotics Technology Middleware
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
#DEPENDS+=	${PYPKGPREFIX}-freetype-py>=1.0.21:../../wip/py-freetype-py
DEPENDS+=	${PYPKGPREFIX}-wordpress-xmlrpc>=2.3:../../wip/py-wordpress-xmlrpc
DEPENDS+=	${PYPKGPREFIX}-nevow>=0.11.1:../../www/py-nevow

USE_LANGUAGES=	# none


REPLACE_PYTHON+=	wasanbon/bin/wasanbon-admin.py \
						wasanbon/template/mgr.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
