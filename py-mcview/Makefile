# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 10:17:26 jihbed Exp $
#

DISTNAME=	mcview-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics
MASTER_SITES=	http://pypi.python.org/packages/source/m/mcview/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi?%3Aaction=search&term=mcview&submit=search
COMMENT=   3D/graph event viewer for high-energy physics event simulations
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/mcview-0.4.0

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/mcview ${WRKSRC}/mcview${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
