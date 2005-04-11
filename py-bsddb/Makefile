# $NetBSD: Makefile,v 1.5 2005/04/11 21:14:57 tvierling Exp $
#

PKGNAME=	${PYPKGPREFIX}-bsddb-0
CATEGORIES=	databases

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.python.org/topics/database/
COMMENT=	Python extension module for Berkeley DB 3 and 4

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_bsddb.c

PY_SETUP_SUBST+=	BLPREFIX=${LOCALBASE}
PY_SETUP_SUBST+=	DBRTPREFIX=${BUILDLINK_PREFIX.db4}
PY_SETUP_SUBST+=	DBPREFIX=${BUILDLINK_PREFIX.db4}

PYTHON_VERSIONS_ACCEPTED= 23

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../databases/db4/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
