# $NetBSD: Makefile,v 1.2 2012/09/28 21:53:00 asau Exp $
#

DISTNAME=		eot-1.1
CATEGORIES=		mail
MASTER_SITES=		http://gwolf.org/soft/eot/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://gwolf.org/soft/eot/
COMMENT=		Expire Old Threads

DEPENDS+=	p5-Mail-Box>=2.038:../../mail/p5-Mail-Box
DEPENDS+=	p5-TimeDate>=1.14:../../time/p5-TimeDate

REPLACE_PERL=	eot

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/eot ${DESTDIR}${PREFIX}/bin/eot

.include "../../mk/bsd.pkg.mk"
