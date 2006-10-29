# $NetBSD: Makefile,v 1.5 2006/10/29 08:32:54 shattered Exp $
#

DISTNAME=		pysnmp-3.4.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysnmp/}

MAINTAINER=		goteki@users.sourceforge.net
HOMEPAGE=		http://pysnmp.sourceforge.net/
COMMENT=		Python SNMP framework

PY_PATCHPLIST=	yes

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py build)

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py install)

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

