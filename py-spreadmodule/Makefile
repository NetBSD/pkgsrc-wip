# $NetBSD: Makefile,v 1.4 2003/05/18 11:36:58 marc Exp $
#

DISTNAME=	SpreadModule-1.3
PKGNAME=	${PYPKGPREFIX}-spreadmodule-1.3
WRKSRC=		${WRKDIR}/SpreadModule-1.3
CATEGORIES=	net
MASTER_SITES=	http://www.python.org/other/spread/
EXTRACT_SUFX=	.tgz

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.python.org/other/spread/
COMMENT=	Python bindings for the Spread messaging service

PYDISTUTILSPKG=	YES
USE_BUILDLINK2=	YES
PYTHON_VERSION_REQD= 22pth

post-patch:
	${MV} ${WRKSRC}/setup.py ${WRKSRC}/setup.py.pre
	${SED}  -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/setup.py.pre > ${WRKSRC}/setup.py

.include "../../net/spread/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
