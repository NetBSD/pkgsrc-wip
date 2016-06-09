# $NetBSD: Makefile,v 1.1 2015/06/01 23:23:05 jihbed Exp $

DISTNAME=	redbaron-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redbaron/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/r/redbaron/
COMMENT=	FST for python to make writing refactoring code a realistic task
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-baron>=0.6.1:../../wip/py-baron

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
