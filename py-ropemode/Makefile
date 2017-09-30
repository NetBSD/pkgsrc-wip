# $NetBSD: Makefile,v 1.1 2012/10/04 17:39:33 jihbed Exp $

DISTNAME=	ropemode-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ropemode/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://rope.sf.net/
COMMENT=	Ropemode, a helper for using rope refactoring library in IDEs
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-rope-[0-9]*:../../devel/py-rope

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
