# $NetBSD: Makefile,v 1.10 2006/04/15 15:33:56 ghen Exp $

DISTNAME=		XaraLX0.4_rev798
PKGNAME=		XaraLX-0.4.798
CATEGORIES=		graphics
MASTER_SITES=		http://downloads.xara.com/opensource/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ghen@NetBSD.org
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
	${SED} -e 's,%%XARALXDIR%%,${XARALXDIR},' < ${FILESDIR}/XaraLX > ${PREFIX}/bin/XaraLX
	${CHMOD} 555 ${PREFIX}/bin/XaraLX

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
