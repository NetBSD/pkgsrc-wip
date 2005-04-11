# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:35 tvierling Exp $
#

DISTNAME=		jgloss-1.0.10
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jgloss/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://jgloss.sourceforge.net/
COMMENT=		Add reading and translation annotations in a Japanese text document

NO_BUILD=		yes
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk14

do-configure:
	${SED} -e 's|@SH@|${SH}|' -e 's|@PKG_JAVA_HOME@|${PKG_JAVA_HOME}|' \
		-e 's|@PREFIX@|${PREFIX}|' ${FILESDIR}/jgloss.in >	   \
		${WRKSRC}/jgloss

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/jgloss
	${INSTALL_DATA} ${WRKSRC}/jgloss.jar ${PREFIX}/libexec/jgloss
	${INSTALL_SCRIPT} ${WRKSRC}/jgloss ${PREFIX}/bin/jgloss
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jgloss
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/jgloss
	${INSTALL_DATA} ${WRKSRC}/doc/jgloss.pdf ${PREFIX}/share/doc/jgloss

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
