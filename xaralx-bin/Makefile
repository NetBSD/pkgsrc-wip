# $NetBSD: Makefile,v 1.11 2007/07/30 15:49:11 jlamwww Exp $

DISTNAME=		XaraLX0.4_rev798
PKGNAME=		XaraLX-0.4.798
CATEGORIES=		graphics
MASTER_SITES=		http://downloads.xara.com/opensource/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.xaraxtreme.org/
COMMENT=		Vector graphics program

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	gtk2
SUSE_VERSION_REQD=	7.3

BUILD_DIRS=		# empty
WRKSRC=			${WRKDIR}/XaraLX
XARALXDIR=		${PREFIX}/share/XaraLX

do-install:
	${INSTALL_DATA_DIR} ${XARALXDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/XaraLX ${XARALXDIR}/
	${INSTALL_DATA_DIR} ${XARALXDIR}/Designs
	${INSTALL_DATA} ${WRKSRC}/Designs/* ${XARALXDIR}/Designs/
	${SED} -e 's,%%XARALXDIR%%,${XARALXDIR},' < ${FILESDIR}/XaraLX > ${PREFIX}/bin/XaraLX
	${CHMOD} 555 ${PREFIX}/bin/XaraLX

.include "../../mk/bsd.pkg.mk"
