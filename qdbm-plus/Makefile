# $NetBSD: Makefile,v 1.1.1.1 2005/11/04 10:21:12 obache Exp $
#

.include "../../wip/qdbm/Makefile.common"

PKGNAME=	qdbm-plus-1.0.0.${QDBM_VERSION}
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qdbm/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://qdbm.sourceforge.net/
COMMENT=	C++ API for QDBM

MY_SUBDIR=	plus
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c++

.include "../../databases/qdbm/buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=         pthread
SUBST_STAGE.pthread=    pre-configure
SUBST_FILES.pthread=    ${MY_SUBDIR}/configure
SUBST_SED.pthread=      -e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
