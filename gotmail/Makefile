# $NetBSD: Makefile,v 1.3 2004/04/25 18:32:17 blef Exp $
#

DISTNAME=		gotmail-0.8.1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gotmail/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://sourceforge.net/projects/gotmail
COMMENT=		Script to download mail from hotmail.com

DEPENDS+=		p5-URI>=1.03:../../www/p5-URI
DEPENDS+=		curl>=7.10.4:../../www/curl
DEPENDS+=		p5-Net-[0-9]*:../../net/p5-Net

NO_BUILD=		YES
NO_BUILDLINK=		YES
USE_PERL5=		YES
REPLACE_PERL=		${WRKSRC}/gotmail

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gotmail ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gotmail/
	${INSTALL_DATA} ${WRKSRC}/sample.gotmailrc ${PREFIX}/share/examples/gotmail/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/examples/gotmail/
	${INSTALL_MAN} ${WRKSRC}/gotmail.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
