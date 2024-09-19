# $NetBSD: Makefile,v 1.3 2012/10/07 17:17:53 asau Exp $
#

DISTNAME=	twitmail-0.42
CATEGORIES=	net
MASTER_SITES=	http://www.hardakers.net/twitmail/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hardakers.net/twitmail/
COMMENT=	Curses-based mail-like interface to twitter
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-DBD-SQLite>=0:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Curses>=0:../../devel/p5-Curses
DEPENDS+=	p5-Curses-UI>=0:../../devel/p5-Curses-UI
DEPENDS+=	p5-Term-ReadKey>=0:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Net-Twitter>=0:../../net/p5-Net-Twitter
DEPENDS+=	p5-TimeDate>=0:../../time/p5-TimeDate
DEPENDS+=	p5-Getopt-GUI-Long>=0:../../wip/p5-Getopt-GUI-Long

PERL5_PACKLIST=	auto/twitmail/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
