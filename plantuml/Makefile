# $NetBSD$

DISTNAME=	plantuml-nodot.1.2021.14.jar
PKGNAME=	${DISTNAME:S/nodot.//:S/.jar//}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=plantuml/}
EXTRACT_SUFX=	#none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://plantuml.sourceforge.net/
COMMENT=	Create some UML diagram using a simple description language
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
USE_JAVA=	run

NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/plantuml

do-build:
	${PRINTF} '%s\n\n' '#! ${SH}' > ${WRKDIR}/plantuml
	${PRINTF} '%s\n%s\n%s %s %s %s\n'					\
		'HEADLESS='							\
		'[ -z "$$DISPLAY" ] && HEADLESS=-Djava.awt.headless=true'	\
		'${PKG_JAVA_HOME}/bin/java'					\
		'$$HEADLESS'							\
		'-jar ${DESTDIR}${PREFIX}/share/plantuml/${DISTNAME}'		\
		'"$$@"' >>${WRKDIR}/plantuml

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}	\
		${DESTDIR}${PREFIX}/share/plantuml/${DISTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/plantuml ${DESTDIR}${PREFIX}/bin/plantuml

.include "../../graphics/graphviz//buildlink3.mk"
.include "../../mk/java-vm.mk"

.include "../../mk/bsd.pkg.mk"
