# $NetBSD$

GITHUB_PROJECT=	jitsi-videobridge
PKGNAME=	${GITHUB_PROJECT}-${JITSI_MEET_VERSION}

HOMEPAGE=	https://github.com/jitsi/jitsi-videobridge/
COMMENT=	WebRTC compatible video router or SFU

DISTINFO_FILE=	${.CURDIR}/../../wip/jitsi-videobridge/distinfo

USE_TOOLS=	bash:run unzip
USE_JAVA2=	8

REPLACE_BASH=	jvb/resources/jvb.sh

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-DskipTests
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStore=${WRKDIR}/keystore
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStorePassword=password

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-configure
SUBST_FILES.java=	jvb/resources/jvb.sh
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
		${UNZIP_CMD} ${WRKSRC}/jvb/target/jitsi-videobridge-2.1-SNAPSHOT-archive.zip
	${MV} ${DESTDIR}${PREFIX}/share/jitsi-videobridge-2.1-SNAPSHOT \
		${DESTDIR}${PREFIX}/share/jitsi-videobridge
	${LN} -s ../share/jitsi-videobridge/jvb.sh \
		${DESTDIR}${PREFIX}/bin/jvb

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
