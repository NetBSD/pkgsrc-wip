# $NetBSD: Makefile,v 1.5 2013/06/04 07:45:22 thomasklausner Exp $
#

DISTNAME=	clonedigger-1.0.9-beta
PKGNAME=	${PYPKGPREFIX}-clonedigger-1.0.9
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/c/clonedigger/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://clonedigger.sourceforge.net/
COMMENT=	Clone Digger aimed to detect similar code in Python
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline

EGG_NAME=	${DISTNAME:S/-beta/_beta/}
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
REPLACE_PYTHON=	clonedigger/clonedigger.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
