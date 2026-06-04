# $NetBSD: Makefile,v 1.2 2012/10/07 17:17:42 asau Exp $
#

DISTNAME=	tnt_3_0_12
PKGNAME=	tnt-3.0.12
CATEGORIES=	math
MASTER_SITES=	http://math.nist.gov/tnt/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://math.nist.gov/tnt/
COMMENT=	Template Numerical Toolkit
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/tnt

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	include/tnt

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.h ${DESTDIR}${PREFIX}/include/tnt


.include "../../mk/bsd.pkg.mk"
