# $NetBSD: Makefile,v 1.3 2012/06/13 06:57:22 othyro Exp $
#

DISTNAME=	arpdig-0.5.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arpdig/}

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://arpdig.sourceforge.net/
COMMENT=	Arp digger utility
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arpdig ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arpdig.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
