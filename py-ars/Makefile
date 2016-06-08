# $NetBSD: Makefile,v 1.1 2015/08/02 22:18:01 jihbed Exp $

DISTNAME=	ARS-0.5b1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=A/ARS/}
EXTRACT_SUFX=	.zip#md5=41d681a4a1e9434d856e18451c197fb0

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://bitbucket.org/glarrain/ars
COMMENT=	Physically-accurate robotics simulator
LICENSE=	2-clause-bsd

DEPENDS+=	vtk>=4.2:../../graphics/vtk

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
