# $NetBSD: Makefile,v 1.3 2012/06/18 14:11:53 uccwen Exp $
#

DISTNAME=	DBIx-Simple-1.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/J/JU/JUERD/
COMMENT=	DBIx::Simple - Easy-to-use OO interface to DBI

DEPENDS+=	p5-DBI>=1.21:../../databases/p5-DBI

PERL5_PACKLIST=	auto/DBIx/Simple/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
