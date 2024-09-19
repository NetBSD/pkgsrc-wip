# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:35 asau Exp $
#

DISTNAME=	oct2py-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oct2py/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/blink1073/oct2py
COMMENT=	Python to GNU Octave bridge --> run m-files from python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

WRKSRC=		${WRKDIR}/oct2py-0.3.4
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/octave/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
