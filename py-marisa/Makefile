# $NetBSD: Makefile,v 1.1 2013/11/04 00:56:50 ishit Exp $
#

.include "../../wip/marisa/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
#CATEGORIES+=	python

COMMENT=	MARISA python module

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	bindings/python

#EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../wip/marisa/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
