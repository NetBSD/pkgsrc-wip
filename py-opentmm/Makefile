# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:36 asau Exp $
#

DISTNAME=	openTMM-0.1.0
PKGNAME=	${PYPKGPREFIX}-opentmm-0.1.0
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/o/openTMM/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mesoscopic.mines.edu/mediawiki/index.php/Free_Python_codes
COMMENT=	OpenTMM is an object-oriented electrodynamic S-matrix
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
#DEPENDS+=	${PYPKGPREFIX}-django-gitrevision>=0.1.4:../../wip/py-django-gitrevision

WRKSRC=		${WRKDIR}/openTMM-0.1.0

USE_LANGUAGES=	c fortran

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
