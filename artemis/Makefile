# $NetBSD: Makefile,v 1.7 2012/06/13 07:07:14 othyro Exp $
#

DISTNAME=		artemis_compiled_v6
PKGNAME=		artemis-6
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.sanger.ac.uk/pub/pathogens/software/artemis/v6/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.sanger.ac.uk/Software/Artemis/
COMMENT=		Genome viewer and annotation too
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/artemis
USE_JAVA=		yes
USE_JAVA2=		yes

NO_BUILD=		yes
INSTALL_DIR=		${PREFIX}/share/Artemis

USE_TOOLS+=		gtar pax

do-install:
	${INSTALL_DATA_DIR} ${INSTALL_DIR}
	cd ${WRKSRC} && pax -rw . -s ',.*/CVS$$,,' -s ',.*/CVS/.*,,' ${INSTALL_DIR:Q}
	${MKDIR} ${WRKSRC}/qwerty
	${SED} < ${FILESDIR}/act > ${WRKSRC}/qwerty/act \
		-e 's:@INSTALL_DIR@:${INSTALL_DIR}:'
	${SED} < ${FILESDIR}/art > ${WRKSRC}/qwerty/art \
		-e 's:@INSTALL_DIR@:${INSTALL_DIR}:'
	${INSTALL_SCRIPT} ${WRKSRC}/qwerty/art ${PREFIX}/bin/art
	${INSTALL_SCRIPT} ${WRKSRC}/qwerty/act ${PREFIX}/bin/act

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
