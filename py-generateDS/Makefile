# $NetBSD: Makefile,v 1.10 2004/07/22 14:34:19 marc Exp $
#

DISTNAME=	generateDS-1.6a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.rexx.com/~dkuhlman/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.rexx.com/~dkuhlman/
COMMENT=	Python XML data binding library

USE_BUILDLINK3=	yes
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
#.include "../../textproc/py-xml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
