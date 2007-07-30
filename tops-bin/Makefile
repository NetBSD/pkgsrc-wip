# $NetBSD: Makefile,v 1.6 2007/07/30 15:49:11 jlamwww Exp $
#

DISTNAME=		Tops
PKGNAME=		tops-bin-20030827
CATEGORIES=		biology
MASTER_SITES=		http://www.sander.embl-ebi.ac.uk/tops/linux/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.sander.embl-ebi.ac.uk/tops/TOPSSoftware.html
COMMENT=		Protein Topology Cartoons Tools

USE_JAVA=		run
PLIST_SUBST+=		TOPS_JAVA_HOME=${PKG_JAVA_HOME:S=${PREFIX}/==}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11

BUILD_DIRS=		# empty

do-configure:
	${SED} -e "s|java|${PKG_JAVA_HOME}/bin/java|" \
		${WRKSRC}/bin/EditTops > ${WRKSRC}/bin/EditTops.bak
	${MV} ${WRKSRC}/bin/EditTops.bak ${WRKSRC}/bin/EditTops

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tops-bin
	${INSTALL_DATA} ${WRKSRC}/docs/Guide.ps ${PREFIX}/share/doc/tops-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tops-bin
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/tops-bin
	${INSTALL_DATA} ${WRKSRC}/classes/TOPS.jar ${PKG_JAVA_HOME}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/Tops ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/EditTops ${PREFIX}/bin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
