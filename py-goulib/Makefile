# $NetBSD: Makefile,v 1.1 2014/06/20 21:36:49 jihbed Exp $

DISTNAME=	Goulib-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Goulib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/goulu/goulib
COMMENT=	Library of useful Python code for scientific + technical applications
LICENSE=	gnu-lgpl-v3

#DEPENDS+=		${PYPKGPREFIX}-Pillow>=2.4.0:../../graphics/py-Pillow
DEPENDS+=		${PYPKGPREFIX}-six>=1.7.2:../../lang/py-six
DEPENDS+=		${PYPKGPREFIX}-networkx>=1.8.1:../../math/py-networkx
DEPENDS+=		${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=		${PYPKGPREFIX}-lxml>=3.3.5:../../textproc/py-lxml
DEPENDS+=		${PYPKGPREFIX}-xlrd>=0.9.2:../../textproc/py-xlrd

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
