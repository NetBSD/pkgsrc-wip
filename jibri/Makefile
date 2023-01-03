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

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	jibri-java-deps-${PKGVERSION_NOREV}.tar.gz
SITES.jibri-java-deps-${PKGVERSION_NOREV}.tar.gz= \
		ftp://ftp.NetBSD.org/pub/NetBSD/misc/khorben/

WRKSRC=		${WRKDIR}/jibri-${PKGVERSION_NOREV}

USE_TOOLS+=	bash:run pax:build

USE_JAVA2=	8

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	--offline
MAVEN_FLAGS+=	-DskipTests
MVN=		mvn ${MAVEN_FLAGS}

REPLACE_BASH=	resources/debian-package/opt/jitsi/jibri/launch.sh

EGDIR=			share/examples/jibri
PKG_SYSCONFSUBDIR=	jitsi/jibri
CONF_FILES=		${EGDIR}/asoundrc ${PKG_SYSCONFDIR}/asoundrc
CONF_FILES+=		${EGDIR}/config.json \
			${PKG_SYSCONFDIR}/config.json
CONF_FILES+=		${EGDIR}/logging.properties \
			${PKG_SYSCONFDIR}/logging.properties
CONF_FILES+=		${EGDIR}/xorg-video-dummy.conf \
			${PKG_SYSCONFDIR}/xorg-video-dummy.conf

SUBST_CLASSES+=		launch
SUBST_STAGE.launch=	post-configure
SUBST_FILES.launch=	resources/debian-package/opt/jitsi/jibri/launch.sh
SUBST_SED.launch=	-e 's,^exec java,exec ${JAVA_BINPREFIX}-java,'
SUBST_SED.launch+=	-e 's,=/etc/,=${PKG_SYSCONFDIR}/,'
SUBST_SED.launch+=	-e 's,=/opt/jitsi/jibri/,=${PREFIX}/share/jibri/,g'

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	share/jibri

.PHONY: create-deps-file
create-deps-file: build
	#XXX disable offline mode for maven before using this rule
	cd ${WRKSRC} && ${MVN} validate
	cd ${WRKDIR} && \
		${PAX} -wz -f jibri-java-deps-${PKGVERSION_NOREV}.tar.gz deps

do-configure:
	cd ${WRKSRC} && ${MVN} versions:set -DnewVersion="${PKGVERSION_NOREV}"

do-build:
	cd ${WRKSRC} && ${MVN} package

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
	${INSTALL_DATA} ${WRKSRC}/target/jibri-${PKGVERSION_NOREV}-jar-with-dependencies.jar \
		${DESTDIR}${PREFIX}/share/jibri/jibri.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
