# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:41 thomasklausner Exp $
#

DISTNAME=	ffc-${MMVERSION}.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/ffc/${MMVERSION}.x/${MMVERSION}.0/+download/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://launchpad.net/ffc
COMMENT=	C++ code generator for multilinear forms

LICENSE=	gnu-lgpl-v3


PYDISTUTILSPKG=	yes

MMVERSION=	1.2

SUBST_CLASSES+=		man
SUBST_FILES.man=	setup.py
SUBST_STAGE.man=	post-patch
SUBST_SED.man=		-e 's|"share", ||g'

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
