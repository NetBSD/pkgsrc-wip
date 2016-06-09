# $NetBSD: Makefile,v 1.1 2014/05/11 22:44:54 jihbed Exp $

DISTNAME=	drawnow-0.44
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=d/drawnow/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/d/drawnow/
COMMENT=	MATLAB-like drawnow
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
