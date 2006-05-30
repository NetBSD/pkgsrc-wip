# $NetBSD: Makefile,v 1.1.1.1 2006/05/30 20:19:02 jsonn Exp $

DISTNAME=	django-0.95pre3007
PKGNAME=	${PYPKGPREFIX}-django-0.95pre3007
CATEGORIES=	www python
MASTER_SITES=	ftp://packages.stura.uni-rostock.de/misc/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework

PYDISTUTILSPKG=	# yes
PYBINMODULE=	# yes
PYTHON_VERSIONS_ACCEPTED=	24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py24-setuptools

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
