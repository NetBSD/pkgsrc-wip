# $NetBSD: Makefile,v 1.19 2014/01/26 15:49:55 thomasklausner Exp $
#

DISTNAME=	generateDS-1.6a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.rexx.com/~dkuhlman/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rexx.com/~dkuhlman/
COMMENT=	Python XML data binding library

PKG_DESTDIR_SUPPORT=	none

PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-xml

REPLACE_PYTHON=	generateDS.py

# set up a convenience link
post-install:
	${CHMOD} 0755 ${PREFIX}/${PYSITELIB}/generateDS.py
	${LN} -sf ${PREFIX}/${PYSITELIB}/generateDS.py \
		${PREFIX}/bin/generateDS${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
#.include "../../textproc/py-xml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
