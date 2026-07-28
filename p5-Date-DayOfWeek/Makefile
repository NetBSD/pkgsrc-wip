# $NetBSD$

DISTNAME=	Date-DayOfWeek-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5 # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Date::DayOfWeek
COMMENT=	Determine the day of the week for any date
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Date-Leapyear>=0:../../time/p5-Date-Leapyear

PERL5_PACKLIST=	auto/Date/DayOfWeek/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
