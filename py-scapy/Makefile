# $NetBSD: Makefile,v 1.2 2005/01/23 21:39:33 marc Exp $
#

DISTNAME=		scapy-0.9.15
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://www.cartel-securite.fr/pbiondi/python/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.cartel-securite.fr/pbiondi/projects/scapy.html
COMMENT=		Interactive packet manipulation tool

PYTHON_VERSIONS_ACCEPTED=	23 22

PYTHON_PATCH_SCRIPTS=		scapy.py

NO_BUILD=	# defined

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scapy.py ${PREFIX}/bin/scapy.py-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
