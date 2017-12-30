# $NetBSD: Makefile,v 1.4 2012/10/04 10:45:25 asau Exp $

DISTNAME=	DBIx-Simple-1.37
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
