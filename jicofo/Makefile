# $NetBSD$

GITHUB_PROJECT=	jicofo
PKGNAME=	${GITHUB_PROJECT}-${JITSI_MEET_VERSION}

HOMEPAGE=	https://github.com/jitsi/jicofo/
COMMENT=	Server side focus component used in Jitsi Meet conferences

DISTINFO_FILE=	${.CURDIR}/../../wip/jicofo/distinfo

USE_TOOLS=	bash:run unzip
USE_JAVA2=	8

REPLACE_BASH=	resources/jicofo.sh

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-DskipTests
MAVEN_FLAGS+=	-Dassembly.skipAssembly=false
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStore=${WRKDIR}/keystore
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStorePassword=password

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-configure
SUBST_FILES.java=	resources/jicofo.sh
SUBST_SED.java=		-e 's,^exec java,exec ${JAVA_BINPREFIX}-java,'

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
	cd ${DESTDIR}${PREFIX}/share && \
		${UNZIP_CMD} ${WRKSRC}/target/jicofo-1.1-SNAPSHOT-archive.zip
	${MV} ${DESTDIR}${PREFIX}/share/jicofo-1.1-SNAPSHOT \
		${DESTDIR}${PREFIX}/share/jicofo
	${LN} -s ../share/jicofo/jicofo.sh \
		${DESTDIR}${PREFIX}/bin/jicofo

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
