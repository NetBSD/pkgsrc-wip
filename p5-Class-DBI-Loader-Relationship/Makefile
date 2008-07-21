# $NetBSD: Makefile,v 1.5 2008/07/21 12:44:33 tnn2 Exp $
#

DISTNAME=	Class-DBI-Loader-Relationship-1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SI/SIMON/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/S/SI/SIMON/
COMMENT=	Easier relationship specification in CDBI::L

#DEPENDS+=	p5-Class-DBI-Loader>=0:../p5-Class-DBI-Loader
BROKEN=		needs p5-Class-DBI-Loader, not yet in pkgsrc
DEPENDS+=	p5-Lingua-EN-Inflect-Number>=1:../../textproc/p5-Lingua-EN-Inflect-Number

PERL5_PACKLIST=	auto/Class/DBI/Loader/Relationship/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
