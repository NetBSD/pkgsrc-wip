# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:15 othyro Exp $
#

DISTNAME=	openTMM-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
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
