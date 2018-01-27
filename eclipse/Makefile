# $NetBSD: Makefile,v 1.7 2015/07/11 13:02:06 khorben Exp $

DISTNAME=	${PKGNAME_NOREV}
PKGNAME=	eclipse-${VERSION}
CATEGORIES=	devel java
MASTER_SITES=	http://www.eclipse.org/downloads/download.php?file=/eclipse/downloads/drops4/R-4.2.1-201209141800/eclipse-SDK-4.2.1-linux-gtk.tar.gz&url=http://download.nus.edu.sg/mirror/eclipse//eclipse/downloads/drops4/R-4.2.1-201209141800/eclipse-SDK-4.2.1-linux-gtk.tar.gz&mirror_id=580
VERSION=	4.2.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eclipse.org/
COMMENT=	Java IDE
LICENSE=	eclipse-license

PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14 openjdk7-bin openjdk7

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}

USE_TOOLS+=		perl
REPLACE_PERL+=		plugins/org.apache.ant_1.8.3.v20120321-1730/bin/antRun.pl
REPLACE_PERL+=		plugins/org.apache.ant_1.8.3.v20120321-1730/bin/complete-ant-cmd.pl
REPLACE_PERL+=		plugins/org.apache.ant_1.8.3.v20120321-1730/bin/runant.pl
REPLACE_PYTHON+=	plugins/org.apache.ant_1.8.3.v20120321-1730/bin/runant.py

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
