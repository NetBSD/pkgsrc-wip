# $NetBSD: Makefile,v 1.6 2013/02/01 22:22:16 thomasklausner Exp $
#

DISTNAME=	mtop-0.6.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mtop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mtop.sourceforge.net/
COMMENT=	Curses-based MySQL server monitor
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Curses>=0:../../devel/p5-Curses
DEPENDS+=	p5-DBD-{mysql,percona}*-[0-9]*:../../databases/p5-DBD-mysql

PERL5_PACKLIST=	auto/mtop/.packlist
USE_LANGUAGES=	# none
MAKE_PARAMS+=	--prefix=${PREFIX}

post-extract:
		rm ${WRKSRC}/cpan2spec.pl

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
