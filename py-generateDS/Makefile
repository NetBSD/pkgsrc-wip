# $NetBSD: Makefile,v 1.5 2003/09/17 22:20:09 marc Exp $
#

DISTNAME=	generateDS-1.4a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.rexx.com/~dkuhlman/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.rexx.com/~dkuhlman/
COMMENT=	Python XML data binding library

USE_BUILDLINK2=	yes
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

PYTHON_PATCH_SCRIPTS=	generateDS.py
PYTHON_VERSIONS_ACCEPTED= 23 23pth 22 22pth

# set up a convenience link
post-install:
	${CHMOD} 0755 ${PREFIX}/${PYSITELIB}/generateDS.py
	${LN} -sf ${PREFIX}/${PYSITELIB}/generateDS.py \
		${PREFIX}/bin/generateDS${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/pyxml/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
