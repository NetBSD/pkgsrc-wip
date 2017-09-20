# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	Exception-Class-TryCatch-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DA/DAGOLDEN/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/D/DA/DAGOLDEN/
COMMENT=	Syntactic try/catch sugar for use with Exception::Class

DEPENDS+=	p5-Exception-Class>=0:../../devel/p5-Exception-Class

PERL5_PACKLIST=		auto/Exception/Class/TryCatch/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
