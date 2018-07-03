# $NetBSD: Makefile,v 1.5 2014/12/31 13:58:34 thomasklausner Exp $

DISTNAME=	logilab-database-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=l/logilab-database/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.logilab.org/project/logilab-database
COMMENT=	Logilab utilities for database manipulation
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-mxDateTime

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
