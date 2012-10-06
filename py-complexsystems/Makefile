# $NetBSD: Makefile,v 1.2 2012/10/06 17:55:29 asau Exp $
#

DISTNAME=	ComplexSystems-0.3.0.5
PKGNAME=	${PYPKGPREFIX}-complexsystems-0.3.0.5
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/C/ComplexSystems/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	 http://bitbucket.org/vgauthier/complex-systems/
COMMENT=	Toolbox for Complex Sytems
LICENSE=	mit

WRKSRC=		${WRKDIR}/ComplexSystems-0.3.0.5

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
