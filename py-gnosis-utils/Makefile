# $NetBSD: Makefile,v 1.2 2003/06/29 17:23:14 marc Exp $
#

DISTNAME=	Gnosis_Utils-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	http://gnosis.cx/download/

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://gnosis.cx/download/
COMMENT=	Classes for working with XML

USE_BUILDLINK2=	YES

PYDISTUTILSPKG=	YES
PYSETUP=	setup_gnosis.py
PY_PATCHPLIST=	YES

post-install:
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py \
		${PREFIX}/${PYSITELIB}/gnosis

.include "../../textproc/pyxml/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
