# $NetBSD: Makefile,v 1.3 2012/10/06 17:55:24 asau Exp $
#

DISTNAME=	Pyccuracy-1.2.23.tar
EGG_NAME=	Pyccuracy-1.2.23
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pyccuracy/
EXTRACT_SUFX=	.gz#md5=5ed9658da71bbc1ba0956833179b4d8a

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.pyccuracy.org/
COMMENT=	Pyccuracy is a BDD style Acceptance Testing framework
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-selenium>=1.0.1:../../wip/py-selenium

WRKSRC=		${WRKDIR}/Pyccuracy-1.2.23
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
