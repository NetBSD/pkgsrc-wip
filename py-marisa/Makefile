# $NetBSD: Makefile,v 1.3 2014/05/24 09:42:33 obache Exp $
#

.include "../../wip/marisa/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
#CATEGORIES+=	python

COMMENT=	MARISA python module

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	bindings/python

#EGG_NAME=	${DISTNAME:S/-/_python-/}

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	bindings/python/setup.py
SUBST_SED.version=	-e s,@VERSION@,${PKGVERSION_NOREV},

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../wip/marisa/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
