# $NetBSD: Makefile,v 1.3 2005/04/11 21:09:50 tvierling Exp $
#

DISTNAME=		artemis_compiled_v6
PKGNAME=		artemis-6
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.sanger.ac.uk/pub/pathogens/software/artemis/v6/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.sanger.ac.uk/Software/Artemis/
COMMENT=

WRKSRC=			${WRKDIR}/artemis
USE_JAVA=		yes
USE_JAVA2=		yes

NO_BUILD=		#DEFINED
INSTALL_DIR=		${PREFIX}/share/Artemis

do-install:

	${INSTALL_DATA_DIR} ${INSTALL_DIR}

	(cd ${WRKSRC} && ${GTAR} cf - .) | (cd ${INSTALL_DIR} && ${GTAR} xf -)

	${MKDIR} ${WRKSRC}/qwerty

	${SED} < ${FILESDIR}/act > ${WRKSRC}/qwerty/act \
		-e 's:@INSTALL_DIR@:${INSTALL_DIR}:'

	${SED} < ${FILESDIR}/art > ${WRKSRC}/qwerty/art \
		-e 's:@INSTALL_DIR@:${INSTALL_DIR}:'

	${INSTALL_SCRIPT} ${WRKSRC}/qwerty/art ${PREFIX}/bin/art
	${INSTALL_SCRIPT} ${WRKSRC}/qwerty/act ${PREFIX}/bin/act

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

