# $NetBSD$

GITHUB_PROJECT=	jibri
GITHUB_TAG=	v8.0
DISTNAME=	v8.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/jitsi/jibri/
COMMENT=	Jitsi BRoadcasting Infrastructure
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/jibri-8.0

USE_TOOLS=	bash:run
USE_JAVA2=	8

REPLACE_BASH=	resources/debian-package/opt/jitsi/jibri/launch.sh

SUBST_CLASSES+=		launch
SUBST_STAGE.launch=	post-configure
SUBST_FILES.launch=	resources/debian-package/opt/jitsi/jibri/launch.sh
SUBST_SED.launch=	-e 's,^exec java,exec ${JAVA_BINPREFIX}-java,'
SUBST_SED.launch+=	-e 's,=/etc/,=${PKG_SYSCONFDIR}/,'
SUBST_SED.launch+=	-e 's,=/opt/jitsi/jibri/,=${PREFIX}/share/jibri/,g'

TOOL_DEPENDS+=		apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=		-DskipTests
MAVEN_FLAGS+=		-Djavax.net.ssl.trustStore=${WRKDIR}/keystore
MAVEN_FLAGS+=		-Djavax.net.ssl.trustStorePassword=password

EGDIR=			share/examples/jibri
CONF_FILES=		${EGDIR}/asoundrc ${PKG_SYSCONFDIR}/jitsi/jibri/asoundrc
CONF_FILES+=		${EGDIR}/config.json \
			${PKG_SYSCONFDIR}/jitsi/jibri/config.json
CONF_FILES+=		${EGDIR}/logging.properties \
			${PKG_SYSCONFDIR}/jitsi/jibri/logging.properties
CONF_FILES+=		${EGDIR}/xorg-video-dummy.conf \
			${PKG_SYSCONFDIR}/jitsi/jibri/xorg-video-dummy.conf

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	share/jibri

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
	${INSTALL_DATA} ${WRKSRC}/lib/logging.properties \
		${DESTDIR}${PREFIX}/${EGDIR}/logging.properties
	${INSTALL_DATA} ${WRKSRC}/resources/debian-package/etc/jitsi/jibri/asoundrc \
		${DESTDIR}${PREFIX}/${EGDIR}/asoundrc
	${INSTALL_DATA} ${WRKSRC}/resources/debian-package/etc/jitsi/jibri/config.json \
		${DESTDIR}${PREFIX}/${EGDIR}/config.json
	${INSTALL_DATA} ${WRKSRC}/resources/debian-package/etc/jitsi/jibri/xorg-video-dummy.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/xorg-video-dummy.conf
	${INSTALL_SCRIPT} ${WRKSRC}/resources/debian-package/opt/jitsi/jibri/launch.sh \
		${DESTDIR}${PREFIX}/bin/jibri
	${INSTALL_DATA} ${WRKSRC}/target/jibri-8.0-SNAPSHOT-jar-with-dependencies.jar \
		${DESTDIR}${PREFIX}/share/jibri/jibri.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
