# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:30 asau Exp $
#

DISTNAME=	EMMSA-0.0.3
PKGNAME=	${PYPKGPREFIX}-emmsa-0.0.3
CATEGORIES=	physics python
MASTER_SITES=	http://pypi.python.org/packages/source/E/EMMSA/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/E/EMMSA/
COMMENT=	Multivariate Statistical Analysis for Electron Microscopy Data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
DEPENDS+=	${PYPKGPREFIX}-Elixir>=0.7.0:../../databases/py-elixir
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.3.0:../../wip/py-pandas

WRKSRC=		${WRKDIR}/EMMSA-0.0.3

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
