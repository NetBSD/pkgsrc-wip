# $NetBSD: Makefile,v 1.2 2012/01/30 05:59:26 noud4 Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
