# $NetBSD: Makefile,v 1.1.1.1 2004/06/01 18:18:13 goteki Exp $
# 

DISTNAME=		pysnmp-3.4.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=   	${MASTER_SITE_SOURCEFORGE:=pysnmp/}

MAINTAINER=		goteki@users.sourceforge.net
HOMEPAGE=		http://pysnmp.sourceforge.net/
COMMENT=		Python SNMP framework

PY_PATCHPLIST=  	yes
USE_BUILDLINK3= 	yes

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py build)

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py install)

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

