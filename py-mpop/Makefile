# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:25 asau Exp $
#

DISTNAME=	mpop-v0.11.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/m/mpop/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mraspaud/mpop
COMMENT=	Meteorological post processing package
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/mpop-v0.11.5

USE_LANGUAGES=	# none

EGDIR=		geo_image.cfg
CONF_FILES=	${EGDIR}/geo_image.cfg ${PKG_SYSCONFDIR}/geo_image.cfg

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
