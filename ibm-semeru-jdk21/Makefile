# $NetBSD$

PKGNAME=	ibm-semeru-jdk21-21.0.6.0
DISTNAME=	ibm-semeru-open-jdk_x64_linux_21.0.6_7_openj9-0.49.0
CATEGORIES=	lang java
MASTER_SITES=	${MASTER_SITE_GITHUB:=ibmruntimes/semeru21-binaries/}releases/download/jdk-21.0.6%2B7_openj9-0.49.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.ibm.com/languages/java/semeru-runtimes/
COMMENT=	IBM Semeru OpenJ9 JVM with OpenJDK 21
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/jdk-21.0.6+7

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	locale x11
#EMUL_REQD=		suse>=15.5

.include "../../mk/bsd.prefs.mk"

# Contains pre-built binaries
CHECK_RELRO_SUPPORTED=	no
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no
CTF_SUPPORTED=		no
MKPIE_SUPPORTED=	no

BUILD_DIRS=		# empty

JAVA_HOME=		${PREFIX}/java/ibm-semeru-jdk21
JAVA_NAME=		ibm-semeru-jdk21
JAVA_UNLIMIT=		datasize
JAVA_WRAPPERS=		jar jarsigner java javac javadoc javap jcmd jconsole
JAVA_WRAPPERS+=		jdb jdeprscan jdeps jdmpview jfr jimage jitserver
JAVA_WRAPPERS+=		jlink jmap jmod jpackage jpackcore jps jrunscript
JAVA_WRAPPERS+=		jshell jstack jstat jwebserver keytool rmiregistry
JAVA_WRAPPERS+=		serialver traceformat

PRINT_PLIST_AWK+=	/^java\/.*\/man\// { sub("\\.gz$$", ""); }

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${JAVA_HOME}
	cd ${WRKSRC} && pax -rw -p ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
