# $NetBSD$

GITHUB_PROJECT=	jicofo
PKGNAME=	${GITHUB_PROJECT}-${JITSI_MEET_VERSION}

HOMEPAGE=	https://github.com/jitsi/jicofo/
COMMENT=	Server side focus component used in Jitsi Meet conferences

DISTINFO_FILE=	${.CURDIR}/../../wip/jicofo/distinfo

USE_TOOLS+=	bash:run unzip
USE_JAVA2=	8

REPLACE_BASH=	resources/jicofo.sh

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-DskipTests
MAVEN_FLAGS+=	-Dassembly.skipAssembly=false
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStore=${WRKDIR}/keystore
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStorePassword=password

EGDIR=		share/examples/jicofo
CONF_FILES=	${EGDIR}/logging.properties \
		${PKG_SYSCONFDIR}/jitsi/jicofo/logging.properties

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${EGDIR}

SUBST_CLASSES+=		java logging
SUBST_STAGE.java=	post-configure
SUBST_FILES.java=	resources/jicofo.sh
SUBST_SED.java=		-e 's,^exec java,exec ${JAVA_BINPREFIX}-java,'
SUBST_STAGE.logging=	post-configure
SUBST_FILES.logging=	resources/jicofo.sh
SUBST_SED.logging=	-e 's,$$SCRIPT_DIR/lib/logging\.properties,${PKG_SYSCONFDIR}/jitsi/jicofo/logging.properties,'

do-configure:
	#XXX this assumes trusted CA certificates are in /etc/openssl/certs
	cd ${WRKSRC} && \
		for cert in /etc/openssl/certs/*.0; do \
			/usr/pkg/java/openjdk11/bin/keytool -importcert \
					-keystore ${WRKDIR}/keystore \
					-noprompt -trustcacerts \
					-storepass password -file "$$cert" \
					-alias $$(basename "$$cert"); done

do-build:
	cd ${WRKSRC} && \
		mvn package ${MAVEN_FLAGS}

do-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/jicofo \
		${DESTDIR}${PREFIX}/share/jicofo-1.1-SNAPSHOT
	cd ${DESTDIR}${PREFIX}/share && \
		${UNZIP_CMD} ${WRKSRC}/target/jicofo-1.1-SNAPSHOT-archive.zip
	${MV} ${DESTDIR}${PREFIX}/share/jicofo-1.1-SNAPSHOT \
		${DESTDIR}${PREFIX}/share/jicofo
	${MV} ${DESTDIR}${PREFIX}/share/jicofo/lib/logging.properties \
		${DESTDIR}${PREFIX}/share/examples/jicofo/logging.properties
	${LN} -sf ../share/jicofo/jicofo.sh \
		${DESTDIR}${PREFIX}/bin/jicofo

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
