# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 11:59:04 jihbed Exp $
#

DISTNAME=	tnt_3_0_12
PKGNAME=	tnt-3.0.12
CATEGORIES=	math
MASTER_SITES=	http://math.nist.gov/tnt/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://math.nist.gov/tnt/
COMMENT=	Template Numerical Toolkit
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/tnt

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	include/tnt

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.h ${DESTDIR}${PREFIX}/include/tnt


.include "../../mk/bsd.pkg.mk"
