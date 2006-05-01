# $NetBSD: Makefile,v 1.6 2006/05/01 14:20:07 shattered Exp $
#

DISTNAME=		ile-0.4
CATEGORIES=		misc
MASTER_SITES=		http://www.jabberstudio.org/files/ile/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jabberstudio.org/projects/ile/
COMMENT=		Email notifier component for jabber

DEPENDS=		p5-Net-Jabber>=1.26:../../chat/p5-Net-Jabber

USE_PERL5=		YES
REPLACE_PERL=	${WRKSRC}/ile.pl

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ile.pl ${PREFIX}/bin/ile.pl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ile/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/ile/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ile/
	${INSTALL_DATA} ${WRKSRC}/ile.xml ${PREFIX}/share/examples/ile/ile.xml

.include "../../mk/bsd.pkg.mk"
