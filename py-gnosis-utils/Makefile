# $NetBSD: Makefile,v 1.5 2003/09/14 22:00:38 marc Exp $
#

DISTNAME=	Gnosis_Utils-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	http://gnosis.cx/download/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://gnosis.cx/download/
COMMENT=	Classes for working with XML

USE_BUILDLINK2=	YES

PYDISTUTILSPKG=	YES
PYSETUP=	setup_gnosis.py
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../textproc/pyxml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
