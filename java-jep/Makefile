# $NetBSD: Makefile,v 1.5 2004/08/13 09:12:03 poppnk Exp $
#

DISTNAME=		jep-2.24
PKGNAME=		java-jep-2.24
CATEGORIES=		math
MASTER_SITES=		http://www.singularsys.com/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.singularsys.com/jep/
COMMENT=		Java Mathematical Expression Parser

USE_BUILDLINK3=		yes
NO_BUILD=		#defined

do-install:
	${INSTALL_DATA} ${WRKSRC}/jep-2.24.jar \
		${PREFIX}/share/classpath/jep.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java-jep/
	${CP} -rf ${WRKSRC}/doc/* ${PREFIX}/share/doc/java-jep/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java-jep/
	${CHMOD} ${SHAREMODE} ${PREFIX}/share/doc/java-jep/

.include "../../mk/bsd.pkg.mk"
