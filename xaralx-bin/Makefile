# $NetBSD: Makefile,v 1.13 2013/04/13 07:58:29 ghen Exp $

DISTNAME=		XaraLX0.4_rev798
PKGNAME=		XaraLX-0.4.798
CATEGORIES=		graphics
MASTER_SITES=		http://downloads.xara.com/opensource/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xaraxtreme.org/
COMMENT=		Vector graphics program

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	gtk2
SUSE_VERSION_REQD=	7.3

PKG_DESTDIR_SUPPORT=	destdir

BUILD_DIRS=		# empty
WRKSRC=			${WRKDIR}/XaraLX
XARALXDIR=		${PREFIX}/share/XaraLX

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${XARALXDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/XaraLX ${DESTDIR}${XARALXDIR}/
	${INSTALL_DATA_DIR} ${DESTDIR}${XARALXDIR}/Designs
	${INSTALL_DATA} ${WRKSRC}/Designs/* ${DESTDIR}${XARALXDIR}/Designs/
	${SED} -e 's,%%XARALXDIR%%,${XARALXDIR},' < ${FILESDIR}/XaraLX > ${DESTDIR}${PREFIX}/bin/XaraLX
	${CHMOD} 555 ${DESTDIR}${PREFIX}/bin/XaraLX

.include "../../mk/bsd.pkg.mk"
