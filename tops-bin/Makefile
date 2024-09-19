# $NetBSD: Makefile,v 1.7 2012/10/07 16:56:50 asau Exp $
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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tops-bin
	${INSTALL_DATA} ${WRKSRC}/docs/Guide.ps ${DESTDIR}${PREFIX}/share/doc/tops-bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/tops-bin
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/tops-bin
	${INSTALL_DATA} ${WRKSRC}/classes/TOPS.jar ${DESTDIR}${PKG_JAVA_HOME}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/Tops ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/EditTops ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
