# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:01:01 jihbed Exp $
#

DISTNAME=	sciproc-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/s/sciproc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/sciproc
COMMENT=	Process scientific multidimensional data

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/sciproc-0.3.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
