# $NetBSD: Makefile,v 1.2 2010/03/10 15:07:55 uccwen Exp $
#

DISTNAME=	pip-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pip/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://pip.openplans.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c9:../../devel/py-setuptools

REPLACE_PYTHON=	${WRKSRC}/*.py

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

#.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
