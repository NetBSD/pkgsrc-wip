# $NetBSD: Makefile,v 1.1.1.1 2009/09/18 07:40:07 obache Exp $
#

PKGNAME=	${PYPKGPREFIX}-cElementTree-0
CATEGORIES=	textproc python

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	C implementation of Python ElementTree API

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_elementtree.c

USE_TOOLS+=	patch

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= EXPATPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+= EXPATRTPREFIX=${BUILDLINK_PREFIX.expat}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
