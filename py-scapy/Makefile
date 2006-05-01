# $NetBSD: Makefile,v 1.6 2006/05/01 14:20:08 shattered Exp $
#

DISTNAME=		scapy-0.9.15
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://www.secdev.org/projects/scapy/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.secdev.org/projects/scapy/
COMMENT=		Interactive packet manipulation tool

PYTHON_VERSIONS_ACCEPTED=	23 22

PYTHON_PATCH_SCRIPTS=		scapy.py

NO_BUILD=	yes

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scapy.py ${PREFIX}/bin/scapy.py-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
