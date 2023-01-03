# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-1.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}
GITHUB_PROJECT=	jigasi
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/jitsi/jigasi/
COMMENT=	Allows regular SIP clients to join Jitsi Meet conferences
LICENSE=	apache-2.0

DIST_SUBDIR=	${GITHUB_PROJECT}
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	jigasi-java-deps-${PKGVERSION_NOREV}.tar.gz
SITES.jigasi-java-deps-${PKGVERSION_NOREV}.tar.gz= \
		ftp://ftp.NetBSD.org/pub/NetBSD/misc/khorben/

USE_TOOLS+=	bash:run pax:build

USE_JAVA2=	8

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	--offline
MAVEN_FLAGS+=	-DskipTests
MVN=		mvn ${MAVEN_FLAGS}

REPLACE_BASH=	jigasi.sh
REPLACE_BASH+=	script/collect-dump-logs.sh
REPLACE_BASH+=	script/graceful_shutdown.sh

EGDIR=			share/examples/${GITHUB_PROJECT}
PKG_SYSCONFSUBDIR=	jitsi/${GITHUB_PROJECT}
CONF_FILES=		${EGDIR}/callstats-java-sdk.properties \
			${PKG_SYSCONFDIR}/callstats-java-sdk.properties
CONF_FILES+=		${EGDIR}/log4j2.xml ${PKG_SYSCONFDIR}/log4j2.xml
CONF_FILES+=		${EGDIR}/logging.properties \
			${PKG_SYSCONFDIR}/logging.properties
CONF_FILES+=		${EGDIR}/sip-communicator.properties \
			${PKG_SYSCONFDIR}/sip-communicator.properties

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-configure
SUBST_FILES.java=	jigasi.sh
SUBST_SED.java=		-e 's,exec java,exec ${JAVA_BINPREFIX}-java,'

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	share/${GITHUB_PROJECT}/lib
INSTALLATION_DIRS+=	share/doc/${GITHUB_PROJECT}

.PHONY: create-deps-file
create-deps-file: build
	#XXX disable offline mode for maven before using this rule
	cd ${WRKSRC} && ${MVN} validate
	cd ${WRKDIR} && \
		${PAX} -wz -f jigasi-java-deps-${PKGVERSION_NOREV}.tar.gz deps

do-configure:
	cd ${WRKSRC} && ${MVN} versions:set -DnewVersion="${PKGVERSION_NOREV}"

do-build:
	cd ${WRKSRC} && \
		mvn package ${MAVEN_FLAGS}

do-install:
	cd ${WRKSRC} && \
		${PAX} -rw lib ${DESTDIR}${PREFIX}/share/${GITHUB_PROJECT}
	${INSTALL_DATA} ${WRKSRC}/target/jigasi-${PKGVERSION_NOREV}.jar \
		${DESTDIR}${PREFIX}/share/${GITHUB_PROJECT}/lib/jigasi.jar
	${INSTALL_DATA} ${WRKSRC}/lib/logging.properties \
		${DESTDIR}${PREFIX}/${EGDIR}/logging.properties
	${INSTALL_SCRIPT} ${WRKSRC}/script/collect-dump-logs.sh \
		${DESTDIR}${PREFIX}/share/${GITHUB_PROJECT}/collect-dump-logs.sh
	${INSTALL_SCRIPT} ${WRKSRC}/script/graceful_shutdown.sh \
		${DESTDIR}${PREFIX}/share/${GITHUB_PROJECT}/graceful_shutdown.sh
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/${GITHUB_PROJECT}/README.md
	cd ${WRKSRC}/jigasi-home && \
		${PAX} -rw * ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/jigasi.sh \
		${DESTDIR}${PREFIX}/share/${GITHUB_PROJECT}/jigasi.sh
	${LN} -sf ../share/${GITHUB_PROJECT}/jigasi.sh \
		${DESTDIR}${PREFIX}/bin/jigasi

CHECK_RELRO_SKIP+=	share/jigasi/lib/native/linux/libhwaddressretriever.so
CHECK_RELRO_SKIP+=	share/jigasi/lib/native/linux-64/libhwaddressretriever.so
CHECK_SHLIBS_SKIP+=	share/jigasi/lib/native/linux/libhwaddressretriever.so
CHECK_SHLIBS_SKIP+=	share/jigasi/lib/native/linux-64/libhwaddressretriever.so

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
