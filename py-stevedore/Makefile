# $NetBSD: Makefile,v 1.2 2015/08/05 22:19:29 jihbed Exp $

DISTNAME=	stevedore-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stevedore/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dreamhost/stevedore
COMMENT=	Manage dynamic plugins for Python applications
LICENSE=	apache-2.0


DEPENDS+=       ${PYPKGPREFIX}-pbr>=1.3.0:../../devel/py-pbr
DEPENDS+=       ${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

WRKSRC=		${WRKDIR}/stevedore-1.7.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
