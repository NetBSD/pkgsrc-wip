# $NetBSD: Makefile,v 1.2 2004/05/08 13:50:07 poppnk Exp $
#

DISTNAME=		dnswalk-2.0.2
WRKSRC=			${WRKDIR}/
CATEGORIES=		wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dnswalk/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://dnswalk.sourceforge.net/
COMMENT=		DNS debugger

DEPENDS+=		p5-Net-DNS>=0.42:../../net/p5-Net-DNS

USE_BUILDLINK3=	YES
USE_PERL5=		YES

REPLACE_PERL=	dnswalk makereports

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dnswalk     ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/makereports ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sendreports ${PREFIX}/bin/
	${INSTALL_MAN}    ${WRKSRC}/dnswalk.1   ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
