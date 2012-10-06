# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:32 asau Exp $
#

DISTNAME=	async-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/a/async/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/a/async/
COMMENT=	Framework to process interdependent tasks in a pool of workers
LICENSE=	modified-bsd #Probably

WRKSRC=	${WRKDIR}/async-0.6.1

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
