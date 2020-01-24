# $NetBSD: Makefile,v 1.3 2015/03/14 21:12:48 jihbed Exp $

DISTNAME=	JabRef-2.10
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	misc
MASTER_SITES=	http://sourceforge.net/projects/jabref/files/jabref/2.10/
EXTRACT_SUFX=	.jar

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://jabref.sourceforge.net/
COMMENT=	JabRef is an advanced reference manager uses the BibTeX format
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin lib/java

do-build:
	printf "#! ${SH}\\nexec ${JAVA_BINPREFIX}-java -jar ${PREFIX}/lib/java/${DISTNAME}.jar \"\$$@\"\\n" > ${WRKSRC}/jabref.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jabref.sh ${DESTDIR}${PREFIX}/bin/jabref
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
