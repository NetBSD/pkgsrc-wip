# $NetBSD: Makefile,v 1.1.1.1 2009/01/06 20:48:00 ficovh Exp $
#

DISTNAME=	DBIx-Simple-1.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/J/JU/JUERD/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/J/JU/JUERD/
COMMENT=	DBIx::Simple - Easy-to-use OO interface to DBI

DEPENDS+=	p5-DBI>=1.21:../../databases/p5-DBI

PERL5_PACKLIST=	auto/DBIx/Simple/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
