# $NetBSD: Makefile,v 1.8 2012/10/04 09:13:32 asau Exp $

DISTNAME=	Class-DBI-Loader-Relationship-1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/S/SI/SIMON/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/Class::DBI::Loader::Relationship
COMMENT=	Easier relationship specification in CDBI::L

DEPENDS+=	p5-Class-DBI-Loader>=0:../../wip/p5-Class-DBI-Loader
DEPENDS+=	p5-Lingua-EN-Inflect-Number>=1:../../textproc/p5-Lingua-EN-Inflect-Number


PERL5_PACKLIST=	auto/Class/DBI/Loader/Relationship/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
