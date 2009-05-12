# $NetBSD: Makefile,v 1.1.1.1 2009/05/12 00:14:47 ficovh Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Test/Assertions/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
