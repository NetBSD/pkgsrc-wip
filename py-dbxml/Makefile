# $NetBSD: Makefile,v 1.1.1.1 2003/12/27 18:31:22 minskim Exp $

DISTNAME=	dbxml-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/src/python
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.sleepycat.com/products/xml.shtml
COMMENT=	Python wrapper for Berkeley DB XML C++ API

PYDISTUTILSPKG=	YES
USE_BUILDLINK2=	YES
NO_CONFIGURE=	YES

.include "../../lang/python/extension.mk"
PYSETUPBUILDARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4} \
			--with-xerces=${BUILDLINK_PREFIX.xerces-c} \
			--with-pathan=${BUILDLINK_PREFIX.libpathan}

.include "../../wip/dbxml/buildlink2.mk"
.include "../../wip/libpathan/buildlink2.mk"
.include "../../textproc/xerces-c/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
