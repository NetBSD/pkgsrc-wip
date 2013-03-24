# $NetBSD: Makefile,v 1.8 2013/03/24 20:37:45 outpaddling Exp $
#

DISTNAME=	ffc-${MMVERSION}.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/ffc/${MMVERSION}.x/${MMVERSION}.0/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/ffc
COMMENT=	C++ code generator for multilinear forms

LICENSE=	gnu-lgpl-v3

FETCH_USING=	curl

PYDISTUTILSPKG=	yes

MMVERSION=	1.2

SUBST_CLASSES+=		man
SUBST_FILES.man=	setup.py
SUBST_STAGE.man=	post-patch
SUBST_SED.man=		-e 's|"share", ||g'

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
