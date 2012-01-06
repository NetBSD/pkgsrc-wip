# $NetBSD: Makefile,v 1.2 2012/01/06 02:18:50 thomasklausner Exp $
#

DISTNAME=	arpdig-0.5.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arpdig/}

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://downloads.sourceforge.net/sourceforge/arpdig/
COMMENT=	Arp digger utility

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arpdig ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arpdig.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
