# $NetBSD: Makefile,v 1.13 2005/11/28 00:27:27 rillig Exp $
#

DISTNAME=	generateDS-1.6a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.rexx.com/~dkuhlman/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.rexx.com/~dkuhlman/
COMMENT=	Python XML data binding library

PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PYTHON_PATCH_SCRIPTS=	generateDS.py
PYTHON_VERSIONS_ACCEPTED= 23 22

# set up a convenience link
post-install:
	${CHMOD} 0755 ${PREFIX}/${PYSITELIB}/generateDS.py
	${LN} -sf ${PREFIX}/${PYSITELIB}/generateDS.py \
		${PREFIX}/bin/generateDS${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
#.include "../../textproc/py-xml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
