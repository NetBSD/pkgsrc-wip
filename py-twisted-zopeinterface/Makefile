# $NetBSD: Makefile,v 1.2 2006/08/31 19:04:06 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

ZI_VERSION=	3.1.0c1
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-zopeinterface-${ZI_VERSION}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	The zope.interface package for Twisted.

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/ZopeInterface-${ZI_VERSION}

DEPENDS+=	${PYPKGPREFIX}-xml>=0.8.4:../../textproc/py-xml

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22

CONFLICTS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
