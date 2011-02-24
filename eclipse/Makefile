# $NetBSD: Makefile,v 1.1 2011/02/24 18:37:31 khorben Exp $
#

DISTNAME=	${PKGNAME_NOREV}
PKGNAME=	eclipse-${VERSION}
CATEGORIES=	devel java
MASTER_SITES=	http://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/helios/SR1/eclipse-java-helios-SR1-linux-gtk.tar.gz&url=http://mirror.netcologne.de/eclipse//technology/epp/downloads/release/helios/SR1/eclipse-java-helios-SR1-linux-gtk.tar.gz&mirror_id=580
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.eclipse.org/
COMMENT=	Java IDE
LICENSE=	eclipse-license

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME:Q}

VERSION=	3.6.1

# XXX: Others might work but might need significant tweaking
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-*

.include "../../mk/bsd.prefs.mk"

NO_BUILD=		yes
CHECK_SHLIBS_SUPPORTED=	no

do-extract:

do-install:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/eclipse > 	\
		${WRKDIR}/.eclipse
	cd ${DESTDIR}${PREFIX} && \
		${TAR} -xzf ${DISTDIR}/${PKGNAME_NOREV}${EXTRACT_SUFX}
	${INSTALL_SCRIPT} ${WRKDIR}/.eclipse ${DESTDIR}${PREFIX}/bin/eclipse

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
