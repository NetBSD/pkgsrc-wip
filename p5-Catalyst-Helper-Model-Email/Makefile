# $NetBSD: Makefile,v 1.1 2014/11/14 09:03:48 noud4 Exp $

DISTNAME=	Catalyst-Helper-Model-Email-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/T/TE/TEDDY/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~teddy/Catalyst-Helper-Model-Email/
COMMENT=	Helper for Mail::Builder::Simple
LICENSE=	${PERL5_LICENSE}

EPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple
DEPENDS+=	p5-ExtUtils-MakeMaker-[0-9]*:../../devel/p5-ExtUtils-MakeMaker

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Helper/Model/Email/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
