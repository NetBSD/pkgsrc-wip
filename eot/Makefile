# $NetBSD: Makefile,v 1.1.1.1 2006/08/13 21:23:32 jtonio Exp $
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

NO_BUILD=	yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/eot ${PREFIX}/bin/eot

.include "../../mk/bsd.pkg.mk"
