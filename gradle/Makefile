# $NetBSD$

DISTNAME=	gradle-2.10-bin
PKGNAME=	${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://services.gradle.org/distributions/
EXTRACT_SUFX=	.zip

MAINTAINER=	asiekierka@gmail.com
HOMEPAGE=	http://gradle.org/
COMMENT=	"Groovy-based Java build system"
LICENSE=	apache-2.0

DEPENDS+=	bash-[0-9]*:../../shells/bash

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_JAVA=	run
USE_JAVA2=	yes
NO_BUILD=	yes

pre-configure:
	${CP} files/gradle-launcher ${WRKSRC}/gradle-launcher

SUBST_CLASSES+=		launcher
SUBST_FILES.launcher=	gradle-launcher
SUBST_STAGE.launcher=	post-configure
SUBST_SED.launcher=	-e 's,@APP_HOME@,${PREFIX}/lib/java/gradle,g'
SUBST_SED.launcher+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.launcher+=	-e 's,@APP_LAUNCHER@,lib/gradle-launcher-${PKGVERSION}\.jar,g'
SUBST_SED.launcher+=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'

INSTALLATION_DIRS=	bin lib/java/gradle/lib lib/java/gradle/lib/plugins lib/java/gradle/lib/plugins/sonar
INSTALLATION_DIRS+=	lib/java/gradle/media share/doc/java/gradle

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gradle-launcher ${DESTDIR}${PREFIX}/bin/gradle
	${INSTALL_SCRIPT} ${WRKSRC}/lib/*.jar ${DESTDIR}${PREFIX}/lib/java/gradle/lib
	${INSTALL_SCRIPT} ${WRKSRC}/lib/plugins/*.jar ${DESTDIR}${PREFIX}/lib/java/gradle/lib/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/lib/plugins/sonar/*.jar ${DESTDIR}${PREFIX}/lib/java/gradle/lib/plugins/sonar
	${INSTALL_SCRIPT} ${WRKSRC}/media/*.icns ${DESTDIR}${PREFIX}/lib/java/gradle/media
	${INSTALL_SCRIPT} ${WRKSRC}/getting-started.html ${DESTDIR}${PREFIX}/share/doc/java/gradle

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
