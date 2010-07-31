# $NetBSD: Makefile,v 1.1.1.1 2010/07/31 12:19:28 jihbed Exp $
#

DISTNAME=	datarray-0.0.3.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/d/datarray/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/fperez/datarray
COMMENT=	NumPy arrays with named axes and named indices

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/datarray-0.0.3
USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
