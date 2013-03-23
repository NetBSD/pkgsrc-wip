# $NetBSD: Makefile,v 1.6 2013/03/23 15:03:23 outpaddling Exp $
#

DISTNAME=	viper-${MMVERSION}.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://launchpad.net/fenics-viper/${MMVERSION}.x/${MMVERSION}.1/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/fenics-viper
COMMENT=	Scientific plotter and run-time visualization module

FETCH_USING=	curl

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

MMVERSION=	1.0

SUBST_CLASSES+=		man
SUBST_FILES.man=	setup.py
SUBST_STAGE.man=	post-patch
SUBST_SED.man=		-e 's|"share", ||g'

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
