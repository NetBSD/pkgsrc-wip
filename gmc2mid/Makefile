# $NetBSD: Makefile,v 1.5 2014/10/09 14:06:27 thomasklausner Exp $
#

DISTNAME=		gmc-0-6
PKGNAME=		gmc2mid-0.6
CATEGORIES=		audio
MASTER_SITES=		http://www.geocities.com/SiliconValley/Software/8918/linux/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Guenthers Midi Compiler, a tool to convert text to midi

WRKSRC=			${WRKDIR}/gmc

USE_TOOLS+=		pax

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/gmc2mid/
	cd ${WRKSRC} && pax -rw lections samples \
		${DESTDIR}${PREFIX}/share/examples/gmc2mid
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gmc2mid
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gmc2mid/README
	${INSTALL_PROGRAM} ${WRKSRC}/gmc ${DESTDIR}${PREFIX}/bin/gmc2mid

.include "../../mk/bsd.pkg.mk"
