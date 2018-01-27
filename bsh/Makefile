# $NetBSD: Makefile,v 1.3 2012/09/24 17:14:40 asau Exp $
#

DISTNAME=	bsh-2.0b4
CATEGORIES=	shells java
MASTER_SITES=	http://www.beanshell.org/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.beanshell.org/
COMMENT=	Java scripting environment
LICENSE=	spl-1.0 AND gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}

PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14
USE_JAVA=		yes
USE_LANGUAGES=		# none

INSTALLATION_DIRS=	bin share/java

do-build:
	printf "#!${SH}\\nJAVA_HEAP_SIZE=96\\nexec ${PKG_JAVA_HOME}/bin/java -Xmx${JAVA_HEAP_SIZE}m -jar ${PREFIX}/share/java/bsh.jar\"\$$@\"\\n" > ${WRKSRC}/bsh.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsh.sh ${DESTDIR}${PREFIX}/bin/bsh
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/share/java/bsh.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
