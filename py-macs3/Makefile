# $NetBSD$

DISTNAME=	macs-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-macs3-3.0.0
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=macs3-project/}
GITHUB_PROJECT=	MACS
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/macs3-project/MACS
COMMENT=	Peak caller aimed at transcription factor binding sites
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-hmmlearn>=0:../../wip/py-hmmlearn

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/simde/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
