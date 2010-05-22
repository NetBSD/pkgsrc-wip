# $NetBSD: Makefile,v 1.1.1.1 2010/05/22 23:02:15 jihbed Exp $
#

DISTNAME=	selenium-1.0.1.tar
EGG_NAME=  selenium-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/s/selenium/
EXTRACT_SUFX=	.gz#md5=4575012325a01b42151392e89f0d0c5a

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/selenium/
COMMENT=	Python binding to selenium Remote Control
#LICENSE=	apache

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/selenium-1.0.1
USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,doc,${PREFIX}/share/doc/py-selenium,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
