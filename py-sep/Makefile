# $NetBSD: Makefile,v 1.1 2015/06/01 20:37:33 jihbed Exp $

DISTNAME=	sep-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sep/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/kbarbary/sep
COMMENT=	Astronomical source extraction and photometry library
LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
