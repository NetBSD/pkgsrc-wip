# $NetBSD: Makefile,v 1.8 2006/02/24 17:21:02 ghen Exp $

DISTNAME=		RecXaraLX0.2a_rev514
PKGNAME=		XaraLX-0.2.514
CATEGORIES=		graphics
MASTER_SITES=		http://downloads.xara.com/opensource/
EXTRACT_SUFX=		.tbz2

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
