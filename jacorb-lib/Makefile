# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 17:57:27 daprice Exp $
#

DISTNAME=		JacORB_${DIST_VERSION}-src
PKGNAME=                JacORB-lib-${PKG_VERSION}
WRKSRC=		        ${WRKDIR}/JacORB_${DIST_VERSION}
CATEGORIES=		corba
MASTER_SITES=		http://www.jacorb.org/releases/${PKG_VERSION}/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.jacorb.org/releases/${PKG_VERSION}/
COMMENT=		Java implementation of the OMG's CORBA jar

DEPENDS+=               apache-ant>=1.5.3.1:../../devel/apache-ant

DIST_VERSION=           1_4_1
PKG_VERSION=            1.4.1

USE_BUILDLINK3=		yes
MAKEFILE=	        build.xml

do-install:
	@${ECHO} "Installing lib"
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	@${INSTALL_DATA} ${WRKSRC}/lib/jacorb.jar  ${PREFIX}/lib/java/JacORB.jar
	@${INSTALL_DATA} ${WRKSRC}/lib/idl.jar  ${PREFIX}/lib/java/IDL.jar

.include "../../lang/sun-jdk13/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=	        ${LOCALBASE}/bin/ant
MAKE_FLAGS=	        -Dpkgsrc.prefix=${PREFIX}
