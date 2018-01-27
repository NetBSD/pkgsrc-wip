# $NetBSD: Makefile,v 1.6 2012/10/07 16:11:39 asau Exp $
#

DISTNAME=	j2me_wireless_toolkit-2_1_01-linux-i386
PKGNAME=	sun-j2me-2.1.1
CATEGORIES=	lang java
MASTER_SITES=

MAINTAINER=	--@--.--
HOMEPAGE=	http://java.sun.com/j2me/
COMMENT=	Sun's Java(tm) 2 Micro Edition Environment
LICENSE=	jdk13-license

ARCHIVE=	http://java.sun.com/products/archive/index.html
DOWNLOAD=	http://java.sun.com/products/j2mewtoolkit/download-2_1.html
EXTRACT_SUFX=	.bin
EXTRACT_CMD=	unzip ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -d ${WRKSRC} # VERY UGLY!

SUPPORT_FILES=

NO_BUILD=	#
NO_FETCH=	#
NO_CONFIGURE=	#
NO_MTREE=	yes

RESTRICTED=		Redistribution of repackaged binaries not permitted
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

JAVA_HOME=	${LOCALBASE}/java/sun-j2me/

MESSAGE_SUBST+=	JAVA_HOME="${JAVA_HOME}"

INTERACTIVE_STAGE=	fetch

_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
   ${ECHO} ;                     \
   ${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing";  \
   ${ECHO} " ${COMMENT} must be fetched into ";          \
   ${ECHO} "   ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}";   \
   ${ECHO} " from:";                   \
   ${ECHO} "   ${DOWNLOAD}";              \
   ${ECHO} "   or ${ARCHIVE}";            \
   ${ECHO} ; \
   ${ECHO} " Click 'Download J2SE ${SHORT}', read and accept the"; \
   ${ECHO} " license, then choose 'Linux self-extracting file'.";    \
   ${ECHO} -e ${END_MESSAGE};             \
   ${ECHO} "======================================================================"

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${JAVA_HOME}/bin
	cp -rf ${WRKSRC}/bin ${DESTDIR}${JAVA_HOME}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${JAVA_HOME}/lib
	cp -rf ${WRKSRC}/lib ${DESTDIR}${JAVA_HOME}/lib

.include "../../mk/bsd.pkg.mk"
