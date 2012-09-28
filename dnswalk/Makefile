# $NetBSD: Makefile,v 1.7 2012/09/28 21:13:25 asau Exp $
#

DISTNAME=		dnswalk-2.0.2
WRKSRC=			${WRKDIR}/
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dnswalk/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://dnswalk.sourceforge.net/
COMMENT=		DNS debugger

DEPENDS+=		p5-Net-DNS>=0.42:../../net/p5-Net-DNS

USE_TOOLS+=		perl:run
REPLACE_PERL=		dnswalk makereports

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dnswalk     ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/makereports ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sendreports ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN}    ${WRKSRC}/dnswalk.1   ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
