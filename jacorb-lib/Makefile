# $NetBSD: Makefile,v 1.8 2012/11/14 00:16:11 othyro Exp $
#

DISTNAME=		JacORB_${DIST_VERSION}-src
PKGNAME=		JacORB-lib-${PKG_VERSION}
CATEGORIES=		lang
MASTER_SITES=		http://www.jacorb.org/releases/${PKG_VERSION}/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.jacorb.org/releases/${PKG_VERSION}/
COMMENT=		Java implementation of the OMG's CORBA jar

BUILD_DEPENDS+=		apache-ant>=1.5.3.1:../../devel/apache-ant

WRKSRC=			${WRKDIR}/JacORB_${DIST_VERSION}

PKG_JVMS_ACCEPTED+=	sun-jdk14
DIST_VERSION=		1_4_1
PKG_VERSION=		1.4.1

MAKE_FILE=		build.xml

do-install:
	@${ECHO} "Installing lib"
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	@${INSTALL_DATA} ${WRKSRC}/lib/jacorb.jar  ${PREFIX}/lib/java/JacORB.jar
	@${INSTALL_DATA} ${WRKSRC}/lib/idl.jar  ${PREFIX}/lib/java/IDL.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		${LOCALBASE}/bin/ant
MAKE_FLAGS=		-Dpkgsrc.prefix=${PREFIX}
