# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:03:21 jihbed Exp $
#

DISTNAME=	FXrays
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/FX/fx/}-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	ftp://ftp.math.uic.edu/pub/t3m/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.uic.edu/~t3m/
COMMENT=	Computes extremal rays with filtering
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	1.0
BUILD_TARGET=	${DISTNAME}.so
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
