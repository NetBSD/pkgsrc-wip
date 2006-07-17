# $NetBSD: Makefile,v 1.2 2006/07/17 21:06:20 unex_linija Exp $

DISTNAME=		jetty-5.1.10
CATEGORIES=		www java
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jetty/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jetty.mortbay.com/
COMMENT=		Jetty is a Java HTTP Server and Servlet Container

NO_BUILD=		yes

USE_JAVA2=		yes
PKG_JVMS_ACCEPTED=	sun-jdk14 sun-jdk15 jdk14
PKG_JVM_DEFAULT=	sun-jdk15

JETTY_HOME=		${PREFIX}/jetty
RCD_SCRIPTS=		jetty

PKG_SYSCONFDIR.jetty=	${JETTY_HOME}/etc
EGDIR=			${PREFIX}/share/examples/jetty
CONF_FILES=		${EGDIR}/jetty.xml ${PKG_SYSCONFDIR}/jetty.xml

FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME:Q} JETTY_HOME=${JETTY_HOME:Q}

do-install:
			${INSTALL_DATA_DIR} ${JETTY_HOME}
			${INSTALL_DATA_DIR} ${EGDIR}
			${INSTALL_DATA} ${WRKSRC}/etc/*.xml ${EGDIR}
			(cd ${WRKSRC} && ${PAX} -rw -pmo . ${JETTY_HOME})

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
