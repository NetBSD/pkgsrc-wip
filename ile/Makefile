# $NetBSD: Makefile,v 1.7 2008/02/03 16:53:11 tnn2 Exp $
#

DISTNAME=		ile-0.4
CATEGORIES=		misc
MASTER_SITES=		http://www.jabberstudio.org/files/ile/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jabberstudio.org/projects/ile/
COMMENT=		Email notifier component for jabber

DEPENDS=		p5-Net-Jabber>=1.26:../../chat/p5-Net-Jabber

USE_TOOLS+=		perl
REPLACE_PERL=	${WRKSRC}/ile.pl

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ile.pl ${PREFIX}/bin/ile.pl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ile/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/ile/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ile/
	${INSTALL_DATA} ${WRKSRC}/ile.xml ${PREFIX}/share/examples/ile/ile.xml

.include "../../mk/bsd.pkg.mk"
