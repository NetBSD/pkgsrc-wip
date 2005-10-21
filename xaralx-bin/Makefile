# $NetBSD: Makefile,v 1.4 2005/10/21 17:10:18 ghen Exp $

DISTNAME=		XaraLX0.1b
PKGNAME=		${DISTNAME:S,LX,LX-,}
CATEGORIES=		graphics
MASTER_SITES=		http://www.cconcepts.co.uk/downloads/
EXTRACT_SUFX=		.tbz2

MAINTAINER=		geert.hendrickx@ua.ac.be
HOMEPAGE=		http://www.xaraxtreme.org/
COMMENT=		Vector graphics program

DEPENDS+=		suse_gtk2>=7.3:../../emulators/${SUSE_DIR_PREFIX}_gtk2

NO_CONFIGURE=		yes
NO_BUILD=		yes

WRKSRC=			${WRKDIR}/XaraLX
XARALXDIR=		${PREFIX}/share/XaraLX

do-install:
	${INSTALL_DATA_DIR} ${XARALXDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/XaraLX ${XARALXDIR}/
	${INSTALL_DATA_DIR} ${XARALXDIR}/Designs
	${INSTALL_DATA} ${WRKSRC}/Designs/* ${XARALXDIR}/Designs/
	${INSTALL_DATA_DIR} ${XARALXDIR}/Resources
	${INSTALL_DATA} ${WRKSRC}/Resources/* ${XARALXDIR}/Resources/
	${SED} -e 's,%%XARALXDIR%%,${XARALXDIR},' < ${FILESDIR}/XaraLX > ${PREFIX}/bin/XaraLX
	${CHMOD} 555 ${PREFIX}/bin/XaraLX

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
