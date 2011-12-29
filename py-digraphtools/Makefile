# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 21:54:57 jihbed Exp $
#

DISTNAME=	digraphtools-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	http://pypi.python.org/packages/source/d/digraphtools/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/dbasden/python-digraphtools
COMMENT=	Python library for working with directed acyclic graphs
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/digraphtools-0.2.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
