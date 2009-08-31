# $NetBSD: Makefile,v 1.1.1.1 2009/08/31 00:38:45 jihbed Exp $
#

DISTNAME=	mpmath-0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://mpmath.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://mpmath.googlecode.com/files/
COMMENT=	Python library for arbitrary-precision floating-point arithmetic
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-gmpy>=:../../wip/py-gmpy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
