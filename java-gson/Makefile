# $NetBSD$

GITHUB_PROJECT=	gson
DISTNAME=	gson-parent-2.8.6
PKGNAME=	java-${DISTNAME:S/parent-//}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/gson/
COMMENT=	Library to convert Java Objects into JSON and back
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/gson-gson-parent-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none

USE_TOOLS+=     bash

do-configure:
	#XXX this assumes trusted CA certificates are in /etc/openssl/certs
	cd ${WRKSRC} && \
		for cert in /etc/openssl/certs/*.0; do \
			/usr/pkg/java/openjdk11/bin/keytool -importcert \
				-keystore ${WRKDIR}/keystore \
				-noprompt -trustcacerts \
				-storepass password -file "$$cert" \
				-alias $$(basename "$$cert"); done

USE_JAVA=	yes
USE_JAVA2=	yes
MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}

SUBST_CLASSES+=		gradle
SUBST_STAGE.gradle=	pre-configure
SUBST_MESSAGE.gradle=	Upgrading to newer gradle, supporting openjdk11
SUBST_FILES.gradle=	gradle/wrapper/gradle-wrapper.properties
SUBST_SED.gradle=	-e 's,gradle-4.4-all.zip,gradle-5.4.1-all.zip,'

do-build:
	${RUN} echo
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${BASH} \
		./gradlew \
		-Djavax.net.ssl.trustStore=${WRKDIR}/keystore \
		-Djavax.net.ssl.trustStorePassword=password \
		build

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
