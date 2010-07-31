# $NetBSD: Makefile,v 1.1.1.1 2010/07/31 12:23:44 jihbed Exp $
#

DISTNAME=	logilab-database-1.1.0.tar
EGG_NAME=	logilab_database-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	databases
MASTER_SITES=	http://pypi.python.org/packages/source/l/logilab-database/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.logilab.org/project/logilab-database
COMMENT=	Logilab utilities for database manipulation
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/logilab-database-1.1.0
USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
