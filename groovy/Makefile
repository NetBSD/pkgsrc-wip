# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=	groovy-binary-1.8.2
PKGNAME=	${DISTNAME:S/binary-//}
CATEGORIES=	lang
MASTER_SITES=	http://dist.groovy.codehaus.org/distributions/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://groovy.codehaus.org/
COMMENT=	Dynamic language for the Java platform
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	# none
NO_BUILD=	yes
USE_TOOLS+=	pax

USE_JAVA=	run
USE_JAVA2=	1.5

INSTALLATION_DIRS=	bin \
			lib/java/${PKGNAME_NOREV} \
			share/doc/${PKGNAME_NOREV}

GROOVY_DOCS=	ANTLR-LICENSE.txt ASM-LICENSE.txt CLI-LICENSE.txt \
		JSR223-LICENSE.txt LICENSE.txt NOTICE.txt
GROOVY_DIRS=	lib conf
GROOVY_BINS=	grape groovy groovyConsole groovyc groovydoc groovysh \
		java2groovy startGroovy

SUBST_CLASSES+=		java
SUBST_STAGE.java=	pre-install
SUBST_MESSAGE.java=	Set Java
SUBST_FILES.java=	bin/startGroovy
SUBST_SED.java=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_SED.java+=	-e 's,@GROOVY_HOME@,${PREFIX}/lib/java/${PKGNAME_NOREV},g'

do-install:
	${INSTALL_DATA} ${WRKSRC}/embeddable/${DISTNAME:S/binary/all/}.jar \
		${DESTDIR}${PREFIX}/lib/java/${PKGNAME_NOREV}

.for f in ${GROOVY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}
.endfor

.for f in ${GROOVY_DIRS}
	cd ${WRKSRC} && pax -rw -pmp ${f} \
		${DESTDIR}${PREFIX}/lib/java/${PKGNAME_NOREV}
.endfor

.for f in ${GROOVY_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} \
		${DESTDIR}${PREFIX}/bin
.endfor

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
