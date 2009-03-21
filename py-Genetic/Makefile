# $NetBSD: Makefile,v 1.8 2009/03/21 19:05:26 jihbed Exp $
#

DISTNAME=	genetic_0.1.1b.orig
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel maths
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/g/genetic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.debian.org/debian/pool/main/g/genetic/
COMMENT=	python-genetic provides genetic algorithms for Python

WRKSRC=		${WRKDIR}/genetic-0.1.1b.orig
USE_LANGUAGES=	# none

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
