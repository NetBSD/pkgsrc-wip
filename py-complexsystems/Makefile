# $NetBSD: Makefile,v 1.3 2014/12/09 21:11:33 jihbed Exp $

DISTNAME=	ComplexSystems-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/ComplexSystems/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://bitbucket.org/vgauthier/complex-systems/
COMMENT=	Toolbox for Complex Sytems
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
