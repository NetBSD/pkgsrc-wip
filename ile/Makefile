# $NetBSD: Makefile,v 1.8 2012/09/30 05:26:08 asau Exp $
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

INSTALLATION_DIRS=	bin

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ile.pl ${DESTDIR}${PREFIX}/bin/ile.pl
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ile/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/ile/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/ile/
	${INSTALL_DATA} ${WRKSRC}/ile.xml ${DESTDIR}${PREFIX}/share/examples/ile/ile.xml

.include "../../mk/bsd.pkg.mk"
