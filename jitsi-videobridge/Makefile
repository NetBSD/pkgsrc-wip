# $NetBSD$

GITHUB_PROJECT=	jitsi-videobridge
GITHUB_TAG=	stable/jitsi-meet_5142
DISTNAME=	jitsi-meet_5142
PKGNAME=	${GITHUB_PROJECT}-2.0.5142
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/jitsi/jitsi-videobridge/
COMMENT=	WebRTC compatible video router or SFU
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-stable-${DISTNAME}
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

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
