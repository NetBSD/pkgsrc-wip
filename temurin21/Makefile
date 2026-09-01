# $NetBSD: $

PKGNAME=	temurin-bin-${GITHUB_RELEASE:S/jdk-//:S/+/./}
CATEGORIES=	lang java
MASTER_SITES=	${MASTER_SITE_GITHUB:=adoptium/}
GITHUB_PROJECT=	temurin21-binaries
GITHUB_RELEASE=	jdk-21.0.12.1+1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://adoptium.net
COMMENT=	OpenJDK Binaries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pax

EMUL_PLATFORMS=		darwin-aarch64 darwin-x86_64 linux-aarch64 linux-x86_64
EMUL_MODULES.linux=	alsa locale x11

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MLinux-*-aarch64} # || make(distinfo) || make(makesum) || make(mdi)
DISTNAME+=	OpenJDK21U-jdk_aarch64_linux_hotspot_21.0.12.1_1
.endif
.if ${MACHINE_PLATFORM:MLinux-*-x86_64} || ${MACHINE_PLATFORM:MNetBSD-*-x86_64} # || make(distinfo) || make(makesum) || make(mdi)
DISTNAME+=	OpenJDK21U-jdk_x64_linux_hotspot_21.0.12.1_1
.  if ${MACHINE_PLATFORM:MNetBSD-*-x86_64}
PLIST_SRC+=	PLIST.Linux-x86_64
.  endif
.endif
.if ${MACHINE_PLATFORM:MDarwin-*-aarch64} # || make(distinfo) || make(makesum) || make(mdi)
DISTNAME+=	OpenJDK21U-jdk_aarch64_mac_hotspot_21.0.12.1_1
.endif
.if ${MACHINE_PLATFORM:MDarwin-*-x86_64} # || make(distinfo) || make(makesum) || make(mdi)
DISTNAME+=	OpenJDK21U-jdk_x64_mac_hotspot_21.0.12.1_1
.endif

.if !defined(DISTNAME)
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.endif

.if ${OPSYS} == "Darwin"
WRKSRC=		${WRKDIR}/jdk-${PKGVERSION_NOREV}.jdk/Contents/Home
.else
WRKSRC=		${WRKDIR}/${GITHUB_RELEASE}
.endif

# Contains pre-built binaries
CHECK_RELRO_SUPPORTED=	no
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no
CTF_SUPPORTED=		no
MKPIE_SUPPORTED=	no

BUILD_DIRS=		# empty

JAVA_HOME=		${PREFIX}/java/temurin-jdk21
JAVA_NAME=		temurin-jdk21
JAVA_UNLIMIT=		datasize
JAVA_WRAPPERS=		jar jarsigner java javac javadoc javap jcmd jconsole
JAVA_WRAPPERS+=		jdb jdeprscan jdeps jfr jhsdb jimage jinfo jlink jmap
JAVA_WRAPPERS+=		jmod jpackage jps jrunscript jshell jstack jstat jstatd
JAVA_WRAPPERS+=		jwebserver keytool rmiregistry serialver

PRINT_PLIST_AWK+=	/^java\/.*\/man\// { sub("\\.gz$$", ""); }

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${JAVA_HOME}
	cd ${WRKSRC} && pax -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
