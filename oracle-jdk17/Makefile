# $NetBSD: Makefile,v 1.10 2020/05/29 10:57:22 abs Exp $

DISTNAME=	jdk-17.0.4.1_linux-x64_bin
PKGNAME=	oracle-jdk17-17.0.4.1
CATEGORIES=	lang java
MASTER_SITES=	https://download.oracle.com/java/17/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.oracle.com/technetwork/java/index.html
COMMENT=	Oracle Java SE 17
LICENSE=	oracle-no-fee-license

JAVA_WRAPPERS+=	appletviewer
JAVA_WRAPPERS+=	apt
JAVA_WRAPPERS+=	extcheck
JAVA_WRAPPERS+=	idlj
JAVA_WRAPPERS+=	jar
JAVA_WRAPPERS+=	jarsigner
JAVA_WRAPPERS+=	java
JAVA_WRAPPERS+=	javac
JAVA_WRAPPERS+=	javadoc
JAVA_WRAPPERS+=	javah
JAVA_WRAPPERS+=	javap
JAVA_WRAPPERS+=	javaws
JAVA_WRAPPERS+=	jcmd
JAVA_WRAPPERS+=	jdb
JAVA_WRAPPERS+=	jhat
JAVA_WRAPPERS+=	jmap
JAVA_WRAPPERS+=	jps
JAVA_WRAPPERS+=	keytool
JAVA_WRAPPERS+=	orbd
JAVA_WRAPPERS+=	policytool
JAVA_WRAPPERS+=	rmic
JAVA_WRAPPERS+=	rmid
JAVA_WRAPPERS+=	rmiregistry
JAVA_WRAPPERS+=	serialver
JAVA_WRAPPERS+=	servertool
JAVA_WRAPPERS+=	tnameserv

RESTRICTED=		Redistribution of repackaged binaries not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EMUL_PLATFORMS=		linux-x86_64

WRKSRC=		${WRKDIR}/jdk-17.0.4.1

USE_TOOLS+=	pax

# Contains pre-built binaries
CHECK_RELRO_SUPPORTED=	no
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no
CTF_SUPPORTED=		no
MKPIE_SUPPORTED=	no

EMUL_MODULES.linux=	alsa locale x11
DIST_ARCH.x86_64=	x64
JAVA_ARCH.x86_64=	amd64
FILES_SUBST+=		JAVA_ARCH=${JAVA_ARCH:Q}
PLIST_SUBST+=		JAVA_ARCH=${JAVA_ARCH:Q}

JAVA_HOME=		${PREFIX}/java/oracle-17
JAVA_NAME=		oracle17
JAVA_UNLIMIT=		datasize
JAVA_LD_LIBRARY_PATH=	${JAVA_HOME}/lib/${JAVA_ARCH}/jli

MESSAGE_SUBST+=	JAVA_HOME=${JAVA_HOME:Q}

EXTRACT_ENV+=	HOME=${WRKDIR}/fake_home

# the following forces compression of jarfiles, which is a huge disk
# space win and trivial to no speed reduction in the face of the
# new class sharing in Java 5+... -tvierling
#EXTRACT_ENV+=	UNPACK200_FLAGS=-Htrue

PRINT_PLIST_AWK+=	/^java\/.*\/man\// { sub("\\.gz$$", ""); }

do-build:
# nothing

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${JAVA_HOME}
	cd ${WRKSRC} && pax -rwp ma . ${DESTDIR}${JAVA_HOME}

#pre-install:
#	# These files are generated the *first* time the package is built
#	${RM} -f ${WRKSRC}/register.html
#	${RM} -f ${WRKSRC}/register_ja.html
#	${RM} -f ${WRKSRC}/register_zh_CN.html

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
