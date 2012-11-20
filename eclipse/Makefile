# $NetBSD: Makefile,v 1.5 2012/11/20 11:42:52 absd Exp $

DISTNAME=	${PKGNAME_NOREV}
PKGNAME=	eclipse-${VERSION}
CATEGORIES=	devel java
MASTER_SITES=	http://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/helios/SR1/eclipse-java-helios-SR1-linux-gtk.tar.gz&url=http://mirror.netcologne.de/eclipse//technology/epp/downloads/release/helios/SR1/eclipse-java-helios-SR1-linux-gtk.tar.gz&mirror_id=580

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.eclipse.org/
COMMENT=	Java IDE
LICENSE=	eclipse-license

PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14 openjdk7-bin openjdk7

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}

VERSION=	3.6.1

# XXX: Others might work but might need significant tweaking
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-*

.include "../../mk/bsd.prefs.mk"

CHECK_SHLIBS_SUPPORTED=	no
WRKSRC=			${WRKDIR}/${PKGBASE}
AUTO_MKDIRS=		YES
USE_TOOLS+=		tar

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/eclipse > 	\
		${WRKDIR}/.eclipse

do-install:
	cd ${WRKDIR} && ${TAR} cf - eclipse | ${TAR} xf - -C ${DESTDIR}${PREFIX}
	${INSTALL_SCRIPT} ${WRKDIR}/.eclipse ${DESTDIR}${PREFIX}/bin/eclipse

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
