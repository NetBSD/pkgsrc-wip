# $NetBSD: Makefile,v 1.7 2014/06/01 12:49:47 thomasklausner Exp $
#

DISTNAME=	ufl-${MMVERSION}.0
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/ufl/${MMVERSION}.x/${MMVERSION}.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://launchpad.net/ufl
COMMENT=	Unified Form Language for finite element discretizations


LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

MMVERSION=	1.2

SUBST_CLASSES+=		man
SUBST_FILES.man=	setup.py
SUBST_STAGE.man=	post-patch
SUBST_SED.man=		-e 's|"share", ||g'

# todo: depends distutils
.include "../../lang/python/extension.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
