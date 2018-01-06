# $NetBSD$

DISTNAME=	Test-Strict-0.40
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MA/MANWAR/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MANWAR/
COMMENT=	Check syntax, presence of use strict; and test coverage
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-Cover>=0.43:../../devel/p5-Devel-Cover
DEPENDS+=	p5-File-Temp>=0.01:../../devel/p5-File-Temp

PERL5_PACKLIST=	auto/Test/Strict/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
