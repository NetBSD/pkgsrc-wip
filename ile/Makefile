# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:21 othyro Exp $
#

DISTNAME=		ile-0.4
CATEGORIES=		misc
MASTER_SITES=		http://www.jabberstudio.org/files/ile/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
