# $NetBSD: Makefile,v 1.3 2012/10/01 21:43:22 asau Exp $
#

DISTNAME=	jakarta-oro-2.0.8
CATEGORIES=	textproc java
MASTER_SITES=	http://apache.tradebit.com/pub//jakarta/oro/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jakarta.apache.org/oro/
COMMENT=	Perl/awk/sh regular expressions for Java
LICENSE=	apache-1.1

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
