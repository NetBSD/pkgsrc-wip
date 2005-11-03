# $NetBSD: Makefile,v 1.8 2005/11/03 15:08:45 obache Exp $
#

DISTNAME=		${MING_DISTNAME}
PKGNAME=		${PYPKGPREFIX}-${MING_PKGNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MING_MASTER_SITES}
EXTRACT_SUFX=		${MING_EXTRACT_SUFX}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Python bindings for Ming library

PY_PATCHPLIST=		yes
PYBINMODULE=		yes

BUILD_TARGET=		mingcmodule.so
BUILD_DIRS=		${WRKSRC}/py_ext

MAKE_ENV+=		PYSITELIB=${PYSITELIB}

.include "../../wip/ming/buildlink3.mk"
.include "../../wip/ming/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
