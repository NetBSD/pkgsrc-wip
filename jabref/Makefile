# $NetBSD: Makefile,v 1.2 2012/10/01 21:43:21 asau Exp $
#

PKGNAME=	jabref-2.6
DISTNAME=	JabRef-2.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jabref/}
EXTRACT_SUFX=	.jar

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://jabref.sourceforge.net/
COMMENT=	JabRef is an advanced reference manager that uses the BibTeX format
LICENSE=	gnu-gpl-v2

USE_JAVA=run
USE_JAVA2=1.5

WRKSRC=			${WRKDIR}
#AUTO_MKDIRS=		yes
USE_TOOLS+=		printf

INSTALLATION_DIRS=	bin lib/java

do-build:
	printf "#! ${SH}\\nexec ${JAVA_BINPREFIX}-java -jar ${PREFIX}/lib/java/${DISTNAME}.jar \"\$$@\"\\n" > ${WRKSRC}/jabref.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jabref.sh ${DESTDIR}${PREFIX}/bin/jabref
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
