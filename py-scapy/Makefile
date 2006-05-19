# $NetBSD: Makefile,v 1.7 2006/05/19 16:51:33 ykomatsu Exp $
#

DISTNAME=		scapy-0.9.15
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://www.secdev.org/projects/scapy/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
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
