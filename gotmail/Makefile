# $NetBSD: Makefile,v 1.1.1.1 2003/06/02 22:15:55 poppnk Exp $
#

DISTNAME=		gotmail_${VERSION}
PKGNAME=		gotmail-${VERSION}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		mail
MASTER_SITES=		http://savannah.nongnu.org/download/gotmail/stable.pkg/${VERSION}/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nongnu.org/gotmail/
COMMENT=		Script to download mail from hotmail.com

VERSION=		0.7.9

USE_BUILDLINK2=		YES
USE_PERL5=		YES
REPLACE_PERL=		${WRKSRC}/gotmail

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gotmail ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gotmail/
	${INSTALL_DATA} ${WRKSRC}/sample.gotmailrc ${PREFIX}/share/examples/gotmail/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/examples/gotmail/
	${INSTALL_MAN} ${WRKSRC}/gotmail.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
