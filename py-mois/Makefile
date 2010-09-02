# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:18:36 jihbed Exp $
#

DISTNAME=	PyMois-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/S/M/m/}
CATEGORIES=	math python
MASTER_SITES=	ftp://ftp.qtzlabs.com/dev/PyMois/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.qtzlabs.com/
COMMENT=	Applications for interactive visualization of numerical methods
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/pymois/chebychev_app.py   ${WRKSRC}/pymois/chebychev${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pymois/integral_app.py	    ${WRKSRC}/pymois/integral${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pymois/interpolation_app.py   ${WRKSRC}/pymois/interpolation${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pymois/lineareq_app.py   ${WRKSRC}/pymois/lineareq${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pymois/roots_app.py   ${WRKSRC}/pymois/roots${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/py-gsl/buildlink3.mk"
#.include "../../x11/py-qt4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
