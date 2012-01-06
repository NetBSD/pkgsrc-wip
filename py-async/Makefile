# $NetBSD: Makefile,v 1.1.1.1 2012/01/06 10:58:51 jihbed Exp $
#

DISTNAME=	async-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/a/async/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/a/async/
COMMENT=	Framework to process interdependent tasks in a pool of workers
LICENSE=	modified-bsd #Probably

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/async-0.6.1

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
