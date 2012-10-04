# $NetBSD: Makefile,v 1.2 2012/10/04 19:11:59 asau Exp $
#

DISTNAME=	Test-Assertions-1.054
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/B/BB/BBC/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/B/BB/BBC/
COMMENT=	Base for test scripts

DEPENDS+=	p5-Getopt-Long>=0:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Log-Trace>=0:../../devel/p5-Log-Trace

PERL5_PACKLIST=	auto/Test/Assertions/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
