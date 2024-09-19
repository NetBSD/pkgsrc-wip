# $NetBSD: Makefile,v 1.1 2012/11/09 17:10:49 jihbed Exp $
#

DISTNAME=	chealpy-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://web.phys.cmu.edu/~yfeng1/chealpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://web.phys.cmu.edu/~yfeng1/chealpy/
COMMENT=	Python Binding of chealpix
LICENSE=	gnu-gpl-v2

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
