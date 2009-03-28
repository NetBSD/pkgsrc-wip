# $NetBSD: Makefile,v 1.10 2009/03/28 21:00:12 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
