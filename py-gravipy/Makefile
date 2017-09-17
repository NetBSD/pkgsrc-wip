# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:41 thomasklausner Exp $

DISTNAME=	GraviPy-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GraviPy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/G/GraviPy/
COMMENT=	Tensor Calculus Package for General Relativity
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.3:../../math/py-sympy

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/doc/py-gravipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
