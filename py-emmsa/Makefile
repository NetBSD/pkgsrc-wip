# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:46 thomasklausner Exp $

DISTNAME=	EMMSA-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/EMMSA/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/E/EMMSA/
COMMENT=	Multivariate Statistical Analysis for Electron Microscopy Data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
DEPENDS+=	${PYPKGPREFIX}-Elixir>=0.7.0:../../databases/py-elixir
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.3.0:../../math/py-pandas

WRKSRC=		${WRKDIR}/EMMSA-0.0.3

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-sqlite2 via py-elixir

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
