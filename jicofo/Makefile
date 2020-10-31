# $NetBSD$

GITHUB_PROJECT=	jicofo
DISTNAME=	644
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/jitsi/jicofo/
COMMENT=	Server side focus component used in Jitsi Meet conferences
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}
USE_TOOLS=	unzip
USE_JAVA=	yes
USE_JAVA2=	9

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-DskipTests
MAVEN_FLAGS+=	-Dassembly.skipAssembly=false
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStore=${WRKDIR}/keystore
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStorePassword=password

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share

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

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
