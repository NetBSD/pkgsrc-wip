# $NetBSD: Makefile,v 1.3 2004/05/02 21:08:33 blef Exp $
#

PKGNAME=	${PYPKGPREFIX}-bsddb-0
CATEGORIES=	databases

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.python.org/topics/database/
COMMENT=	Python extension module for Berkeley DB 3 and 4

USE_BUILDLINK3=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_bsddb.c

PY_SETUP_SUBST+=	BLPREFIX=${LOCALBASE}
PY_SETUP_SUBST+=	DBRTPREFIX=${BUILDLINK_PREFIX.db4}
PY_SETUP_SUBST+=	DBPREFIX=${BUILDLINK_PREFIX.db4}

PYTHON_VERSIONS_ACCEPTED= 23 23pth

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
