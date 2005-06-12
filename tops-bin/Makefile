# $NetBSD: Makefile,v 1.3 2005/06/12 23:51:28 kristerw Exp $
#

DISTNAME=		Tops
PKGNAME=		tops-bin-20030827
CATEGORIES=		biology
MASTER_SITES=		http://www.sander.embl-ebi.ac.uk/tops/linux/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.sander.embl-ebi.ac.uk/tops/TOPSSoftware.html
COMMENT=		Protein Topology Cartoons Tools

USE_JAVA=		yes

CHECK_SHLIBS=   	no

NO_BUILD=		yes

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

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/java-vm.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
