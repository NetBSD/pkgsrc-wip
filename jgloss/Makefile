# $NetBSD: Makefile,v 1.4 2012/10/01 21:38:52 asau Exp $
#

DISTNAME=		jgloss-1.0.10
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jgloss/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jgloss.sourceforge.net/
COMMENT=		Add reading and translation annotations in a Japanese text document

NO_BUILD=		yes
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk14

do-configure:
	${SED} -e 's|@SH@|${SH}|' -e 's|@PKG_JAVA_HOME@|${PKG_JAVA_HOME}|' \
		-e 's|@PREFIX@|${PREFIX}|' ${FILESDIR}/jgloss.in >	   \
		${WRKSRC}/jgloss

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libexec/jgloss
	${INSTALL_DATA} ${WRKSRC}/jgloss.jar ${DESTDIR}${PREFIX}/libexec/jgloss
	${INSTALL_SCRIPT} ${WRKSRC}/jgloss ${DESTDIR}${PREFIX}/bin/jgloss
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/jgloss
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/jgloss
	${INSTALL_DATA} ${WRKSRC}/doc/jgloss.pdf ${DESTDIR}${PREFIX}/share/doc/jgloss

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
