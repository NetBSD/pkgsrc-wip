# $NetBSD: Makefile,v 1.1 2015/08/05 22:00:16 jihbed Exp $

DISTNAME=	IProgress-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=I/IProgress/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/I/IProgress/
COMMENT=	Text progress bar library for Python
LICENSE=	modified-bsd OR gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-ipython>=2.0.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
