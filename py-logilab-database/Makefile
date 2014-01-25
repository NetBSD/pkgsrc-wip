# $NetBSD: Makefile,v 1.3 2014/01/25 10:38:22 thomasklausner Exp $

DISTNAME=	logilab-database-1.1.0
EGG_NAME=	logilab_database-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	http://pypi.python.org/packages/source/l/logilab-database/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.logilab.org/project/logilab-database
COMMENT=	Logilab utilities for database manipulation
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-mxDateTime

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
