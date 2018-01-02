# $NetBSD: Makefile,v 1.7 2014/06/01 12:49:42 thomasklausner Exp $
#

DISTNAME=	instant-${MMVERSION}.0
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/instant/${MMVERSION}.x/${MMVERSION}.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://launchpad.net/instant
COMMENT=	Instant inlining of C and C++ code in Python


LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

MMVERSION=	1.2

SUBST_CLASSES+=		man
SUBST_FILES.man=	setup.py
SUBST_STAGE.man=	post-patch
SUBST_SED.man=		-e 's|"share", ||g'

# todo: depends on swig, distutils
.include "../../lang/python/extension.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
