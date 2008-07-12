# $NetBSD: Makefile,v 1.5 2008/07/12 00:20:01 milosn Exp $

ZI_VERSION=	3.3.0
DISTNAME=	zope.interface-${ZI_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-zopeinterface-${ZI_VERSION}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.zope.org/Products/ZopeInterface/${ZI_VERSION}/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	The zope.interface package for Twisted.

DEPENDS+=	${PYPKGPREFIX}-xml>=0.8.4:../../textproc/py-xml

PYDISTUTILSPKG=			yes
_PYSETUPTOOLSINSTALLARGS+=	--old-and-unmanageable

CONFLICTS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*

#.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
