# $NetBSD: Makefile,v 1.1 2015/01/11 23:37:24 jihbed Exp $

DISTNAME=	sima-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sima/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.losonczylab.org/sima/
COMMENT=	Software for analysis of sequential imaging data
LICENSE=	gnu-gpl-v2

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
