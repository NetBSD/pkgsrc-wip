# $NetBSD: Makefile,v 1.1 2012/09/11 14:01:44 jihbed Exp $
#

DISTNAME=	oct2py-0.3.4
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/o/oct2py/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/blink1073/oct2py
COMMENT=	Python to GNU Octave bridge --> run m-files from python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/oct2py-0.3.4
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/octave/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
