# $NetBSD: Makefile,v 1.1.1.1 2010/03/09 13:24:22 uccwen Exp $
#

DISTNAME=	pip-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/d/dexml/

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
