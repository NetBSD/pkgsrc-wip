# $NetBSD: Makefile,v 1.1 2014/07/19 10:04:31 jihbed Exp $

DISTNAME=	yams-0.39.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yams/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.logilab.org/project/yams
COMMENT=	Entity / relation schema
#LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-logilab-common-[0-9]*:../../devel/py-logilab-common
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-logilab-common

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
