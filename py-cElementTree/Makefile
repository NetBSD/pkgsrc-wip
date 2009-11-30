# $NetBSD: Makefile,v 1.3 2009/11/30 11:34:20 obache Exp $
#

DISTNAME=	cElementTree-1.0.5-20051216
PKGNAME=	${PYPKGPREFIX}-cElementTree-1.0.5
CATEGORIES=	textproc python
MASTER_SITES=	http://effbot.org/media/downloads/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.effbot.org/zone/celementtree.htm
COMMENT=	C implementation of Python ElementTree API

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

USE_LANGUAGES=		c

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py24"

C_MODULE_NAME=		cElementTree

DEPENDS+=		${PYPKGPREFIX}-elementtree-[0-9]*:../../textproc/py-elementtree

SUBST_CLASSES+=		fixsetup
SUBST_STAGE.fixsetup=	pre-configure
SUBST_FILES.fixsetup=	setup.py
SUBST_VARS.fixsetup=	EXPATPREFIX

EXPATPREFIX=	${BUILDLINK_PREFIX.expat:Q}

.else

C_MODULE_NAME=		_elementtree

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_elementtree.c

USE_TOOLS+=	patch

PY_SETUP_SUBST+= EXPATPREFIX=${BUILDLINK_PREFIX.expat}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

.include "../../lang/python/srcdist.mk"
.endif

PLIST_SUBST+=	C_MODULE_NAME=${C_MODULE_NAME:Q}

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
