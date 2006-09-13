# $NetBSD: Makefile,v 1.14 2006/09/13 12:47:36 obache Exp $
#

DISTNAME=		ming-py-0.3.0
PKGNAME=		${PYPKGPREFIX}-ming-0.3.0
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ming/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Python bindings for Ming library

PY_PATCHPLIST=		yes
PYBINMODULE=		yes

WRKSRC=			${WRKDIR}/ming-0.3.0/py_ext

PYDISTUTILSPKG=		yes

BUILDLINK_API_DEPENDS.ming=	ming>=0.3.0

.include "../../wip/ming/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
