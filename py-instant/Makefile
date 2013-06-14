# $NetBSD: Makefile,v 1.6 2013/06/14 18:43:01 thomasklausner Exp $
#

DISTNAME=	instant-${MMVERSION}.0
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/instant/${MMVERSION}.x/${MMVERSION}.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/instant
COMMENT=	Instant inlining of C and C++ code in Python

FETCH_USING=	curl

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
