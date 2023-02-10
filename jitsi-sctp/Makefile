# $NetBSD$

GITHUB_TAG=	45bf9f296167f79a52cdc1b0e93bbfa4dc8c4976
DISTNAME=	jitsi-sctp-1.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jitsi/jitsi-sctp/
COMMENT=	JNI wrapper around the usrsctp lib
LICENSE=	apache-2.0

DISTINFO_FILE=	${.CURDIR}/../../wip/jitsi-sctp/distinfo
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	jitsi-sctp-java-deps-1.0.tar.gz
DISTFILES+=	usrsctp-c1d6cb3bf4344e01e7d0b3157f4e7103d55b0fbf.tar.gz
SITES.jitsi-sctp-java-deps-1.0.tar.gz= \
		ftp://ftp.NetBSD.org/pub/NetBSD/misc/khorben/
SITES.usrsctp-c1d6cb3bf4344e01e7d0b3157f4e7103d55b0fbf.tar.gz= \
		-${MASTER_SITE_GITHUB:=sctplab/usrsctp/archive/c1d6cb3bf4344e01e7d0b3157f4e7103d55b0fbf.tar.gz}

USE_LANGUAGES+=	c

USE_TOOLS+=	pax:build

USE_JAVA2=	yes

PKG_JVMS_ACCEPTED=	openjdk8

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	--offline
MAVEN_FLAGS+=	-DskipTests
MAVEN_FLAGS+=	-Dassembly.skipAssembly=false
MVN=		mvn ${MAVEN_FLAGS}

.include "../../mk/java-vm.mk"

SUBST_CLASSES+=		java-home
SUBST_STAGE.java-home=	pre-configure
SUBST_FILES.java-home=	jniwrapper/native/pom.xml
SUBST_SED.java-home=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},'

.PHONY: create-deps-file
create-deps-file: build
	#XXX disable offline mode for maven before using this rule
	cd ${WRKSRC} && ${MVN} validate
	cd ${WRKDIR} && \
		${PAX} -wz -f jitsi-sctp-java-deps-${PKGVERSION_NOREV}.tar.gz deps

post-extract:
	${MV} ${WRKDIR}/usrsctp-c1d6cb3bf4344e01e7d0b3157f4e7103d55b0fbf \
		${WRKSRC}/usrsctp/usrsctp

do-build:
	cd ${WRKSRC} && ${MVN} package -DbuildSctp -DbuildNativeWrapper -DdeployNewJnilib

do-install:
	cd ${WRKSRC} && ${MVN} install -DbuildSctp -DbuildNativeWrapper -DdeployNewJnilib

.include "../../mk/bsd.pkg.mk"
