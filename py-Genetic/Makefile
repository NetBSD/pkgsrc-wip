# $NetBSD: Makefile,v 1.11 2012/10/06 17:13:24 asau Exp $
#

DISTNAME=	genetic_0.1.1b.orig
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/g/genetic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.debian.org/debian/pool/main/g/genetic/
COMMENT=	Python-genetic provides genetic algorithms for Python

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
