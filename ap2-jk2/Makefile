# $NetBSD: Makefile,v 1.3 2004/12/02 16:38:56 thomasklausner Exp $
#

DISTNAME=	jakarta-tomcat-connectors-jk2-${AP_JK_VER}-src
PKGNAME=	ap2-jk2-${AP_JK_VER}
CATEGORIES=	www
MASTER_SITES=	http://www.apache.org/dist/jakarta/tomcat-connectors/jk2/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jakarta.apache.org/tomcat/
COMMENT=	Apache2 JK2 module for connecting to Tomcat using AJP1X

WRKSRC=		${WRKDIR}/${DISTNAME}/jk/native2
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
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

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
