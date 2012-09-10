# $NetBSD: Makefile,v 1.2 2012/09/10 15:00:41 jihbed Exp $
#

DISTNAME=	jakarta-oro-2.0.8
CATEGORIES=	textproc java
MASTER_SITES=	http://apache.tradebit.com/pub//jakarta/oro/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jakarta.apache.org/oro/
COMMENT=	Perl/awk/sh regular expressions for Java
LICENSE=	apache-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	yes
PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/jakarta-oro

do-install:
	${INSTALL_DATA} ${WRKSRC}/jakarta-oro-2.0.8.jar\
		${DESTDIR}${PREFIX}/lib/java/jakarta-oro.jar
	cd ${WRKSRC}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/jakarta-oro


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
