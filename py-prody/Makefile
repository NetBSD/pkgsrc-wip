# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 11:12:55 jihbed Exp $
#

DISTNAME=	ProDy-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/S/D/d/}
CATEGORIES=	biology python
MASTER_SITES=	http://pypi.python.org/packages/source/P/ProDy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.pitt.edu/~ahb12/software/ProDy
COMMENT=	Python Package for Protein Structural Dynamics Analysis
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ProDy-0.2.0

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
