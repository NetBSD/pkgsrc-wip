# $NetBSD: Makefile,v 1.2 2003/06/15 14:09:22 marc Exp $
#

DISTNAME=		generateDS-1.2a
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		http://www.rexx.com/~dkuhlman/

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.rexx.com/~dkuhlman/
COMMENT=		Python XML data binding library

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_PATCH_SCRIPTS=	generateDS.py

PYTHON_VERSIONS_ACCEPTED= 22 22pth

# set up a convenience link
post-install:
	${CHMOD} 0755 ${PREFIX}/${PYSITELIB}/generateDS.py
	${LN} -s ${PREFIX}/${PYSITELIB}/generateDS.py \
		${PREFIX}/bin/generateDS

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/pyxml/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
