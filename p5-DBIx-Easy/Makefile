# $NetBSD: Makefile,v 1.2 2012/10/04 10:45:25 asau Exp $
#

DISTNAME=	DBIx-Easy-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/H/HO/HORNBURG/
COMMENT=	Easy to Use DBI interface

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/DBIx/Easy/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
