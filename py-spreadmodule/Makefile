# $NetBSD: Makefile,v 1.6 2003/10/24 22:28:47 marc Exp $
#

DISTNAME=	SpreadModule-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SpreadModule/spreadmodule/}
CATEGORIES=	net
MASTER_SITES=	http://www.python.org/other/spread/
EXTRACT_SUFX=	.tgz

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.python.org/other/spread/
COMMENT=	Python bindings for the Spread messaging service

PYDISTUTILSPKG=	YES
USE_BUILDLINK2=	YES

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth

post-patch:
	${MV} ${WRKSRC}/setup.py ${WRKSRC}/setup.py.pre
	${SED}  -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/setup.py.pre > ${WRKSRC}/setup.py

.include "../../net/spread/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
