# $NetBSD: Makefile,v 1.1.1.1 2005/11/04 10:18:47 obache Exp $
#

.include "../../wip/qdbm/Makefile.common"

PKGNAME=	qdbm-cgi-0.0.1.${QDBM_VERSION}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qdbm/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://qdbm.sourceforge.net/
COMMENT=	CGI script of QDBM

MY_SUBDIR=	cgi
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=	yes

.include "../../databases/qdbm/buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=         pthread
SUBST_STAGE.pthread=    pre-configure
SUBST_FILES.pthread=    ${MY_SUBDIR}/configure
SUBST_SED.pthread=      -e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
