# $NetBSD: Makefile,v 1.1 2014/11/15 10:08:09 noud4 Exp $

DISTNAME=	Safe-2.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RG/RGARCIA/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~rgarcia/Safe/
COMMENT=	Compile and execute code in restricted compartments

DEPENDS+=	p5-ExtUtils-MakeMaker>0:../../devel/p5-ExtUtils-MakeMaker

USE_LANGUAGES+=	# empty
PERL5_PACKLIST= auto/Safe/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
