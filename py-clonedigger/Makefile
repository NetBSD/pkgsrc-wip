# $NetBSD: Makefile,v 1.3 2012/10/06 17:55:27 asau Exp $
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

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
