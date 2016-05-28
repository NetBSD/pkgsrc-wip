# $NetBSD: Makefile,v 1.13 2014/06/22 19:57:10 thomasklausner Exp $
#

DISTNAME=	jakarta-tomcat-connectors-jk2-${AP_JK_VER}-src
PKGNAME=	ap2-jk2-${AP_JK_VER}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	https://archive.apache.org/dist/tomcat/tomcat-connectors/jk2/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tomcat.apache.org/
COMMENT=	Apache2 JK2 module for connecting to Tomcat using AJP1X


WRKSRC=		${WRKDIR}/${DISTNAME}/jk/native2
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

AP_JK_VER=	2.0.4
BUILD_TARGET=	jk2-build-apxs
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

do-install:
	@(cd ${WRKSRC}/server/apache2;		\
	${GMAKE} -f Makefile.apxs install;	\
	${APXS} -e -A -n jk2 mod_jk2.la)
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/jk/conf/workers.properties \
		${EGDIR}

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
