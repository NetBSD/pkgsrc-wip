# $NetBSD: Makefile,v 1.3 2012/03/10 21:25:17 genolopolis Exp $
#

DISTNAME=	selenium-2.20.0.tar
EGG_NAME=  selenium-2.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/s/selenium/
EXTRACT_SUFX=	.gz#md5=4575012325a01b42151392e89f0d0c5a

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/selenium/
COMMENT=	Python binding to selenium Remote Control
#LICENSE=	apache

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/selenium-2.20.0
USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,doc,${PREFIX}/share/doc/py-selenium,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
