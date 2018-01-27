# $NetBSD$

DISTNAME=	louvain-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/61/0f/ec441b9d8ccd951dbd1ec0330cafffade67f4ebef6847ff7e5b4d004c4c9/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/vtraag/louvain-igraph
COMMENT=	Methods of community detection in large networks
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/louvain-0.5.3

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../wip/igraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
