# $NetBSD: Makefile,v 1.20 2020/08/31 18:07:02 wiz Exp $

DISTNAME=	DBIx-Class-ResultSet-RecursiveUpdate-0.42
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DBIx-Class-ResultSet-RecursiveUpdate
COMMENT=	Like update_or_create - but recursive
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan-[0-9]*:../../devel/p5-Carp-Clan
DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-IntrospectableM2M-[0-9]*:../../databases/p5-DBIx-Class-IntrospectableM2M
DEPENDS+=	p5-Data-Dumper-Concise-[0-9]*:../../devel/p5-Data-Dumper-Concise
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator
#TEST_DEPENDS+=	p5-Test-DBIC-ExpectedQueries-[0-9]*:../../devel/p5-Test-DBIC-ExpectedQueries
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap
TEST_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
TEST_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/ResultSet/RecursiveUpdate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
