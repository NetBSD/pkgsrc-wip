# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 21:31:41 jihbed Exp $
#

DISTNAME=	hcluster-0.2.0.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	parallel math python
MASTER_SITES=	http://pypi.python.org/packages/source/h/hcluster/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/scipy-cluster/
COMMENT=	Hierarchical Clustering Package For Scipy
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/hcluster-0.2.0
USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
