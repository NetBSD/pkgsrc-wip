# $NetBSD: Makefile,v 1.1.1.1 2009/04/03 22:37:10 pettai Exp $
#

DISTNAME=	Mail-RFC822-Address-0.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5 
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://search.cpan.org/~pdwarren/Mail-RFC822-Address-0.3/
COMMENT=	Perl extension for validating email addresses according to RFC822

DEPENDS+=	p5-ExtUtils-MakeMaker-[0-9]*:../../devel/p5-ExtUtils-MakeMaker

PERL5_PACKLIST=	auto/Mail/RFC822/Address/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
