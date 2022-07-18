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

USE_TOOLS+=	bash
USE_TOOLS+=	pax:run
USE_JAVA2=	8

REPLACE_BASH=	jigasi.sh

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-Djavax.net.ssl.trustStore=${WRKDIR}/keystore
MAVEN_FLAGS+=	-Djavax.net.ssl.trustStorePassword=password

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-configure
SUBST_FILES.java=	jigasi.sh
SUBST_SED.java=		-e 's,exec java,exec ${JAVA_BINPREFIX}-java,'

EGDIR=		share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR= jitsi/${PKGBASE}
CONF_FILES=	${EGDIR}/callstats-java-sdk.properties \
		${PKG_SYSCONFDIR}/callstats-java-sdk.properties
CONF_FILES+=	${EGDIR}/log4j2.xml ${PKG_SYSCONFDIR}/log4j2.xml
CONF_FILES+=	${EGDIR}/sip-communicator.properties \
		${PKG_SYSCONFDIR}/sip-communicator.properties

INSTALLATION_DIRS=	bin share/${PKGBASE}/lib ${EGDIR} share/doc/${PKGBASE}

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
	cd ${WRKSRC} && \
		${PAX} -rw lib ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/target/jigasi-1.1-SNAPSHOT.jar \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/lib/jigasi.jar
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README.md
	cd ${WRKSRC}/jigasi-home && \
		${PAX} -rw * ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/jigasi.sh \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/jigasi.sh
	${LN} -sf ../share/${PKGBASE}/jigasi.sh \
		${DESTDIR}${PREFIX}/bin/jigasi

CHECK_RELRO_SKIP+=	share/jigasi/lib/native/linux/libhwaddressretriever.so
CHECK_RELRO_SKIP+=	share/jigasi/lib/native/linux-64/libhwaddressretriever.so
CHECK_SHLIBS_SKIP+=	share/jigasi/lib/native/linux/libhwaddressretriever.so
CHECK_SHLIBS_SKIP+=	share/jigasi/lib/native/linux-64/libhwaddressretriever.so

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
