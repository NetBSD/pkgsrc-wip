# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	lifelines-0.2.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lifelines/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/l/lifelines/
COMMENT=	Including Kaplan Meier, Nelson Aalen and regression
LICENSE=	mit

WRKSRC=		${WRKDIR}/lifelines-0.2.2.2
USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.12.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
