# $NetBSD: Makefile,v 1.1.1.1 2003/04/07 06:13:42 marc Exp $
#

DISTNAME=	SpreadModule-1.3
PKGNAME=	${PYPKGPREFIX}-spreadmodule-1.3
CATEGORIES=	net
MASTER_SITES=	http://www.python.org/other/spread/
EXTRACT_SUFX=	.tgz

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.python.org/other/spread/
COMMENT=	Python bindings for the Spread messaging service

WRKSRC=		${WRKDIR}/SpreadModule-1.3
PYDISTUTILSPKG=	YES
USE_BUILDLINK2=	YES
#LDFLAGS+=	-lpthread
PTHREAD_OPTS+=	require

post-patch:
	${MV} ${WRKSRC}/setup.py ${WRKSRC}/setup.py.pre
	${SED}  -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/setup.py.pre > ${WRKSRC}/setup.py

.include "../../net/spread/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
