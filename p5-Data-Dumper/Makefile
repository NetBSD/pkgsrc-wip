# $NetBSD: Makefile,v 1.1 2014/11/15 09:20:19 noud4 Exp $

DISTNAME=	Data-Dumper-2.154
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SM/SMUELLER/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~smueller/Data-Dumper/
COMMENT=	Stringified perl data structures

DEPENDS+=	p5-Test-Simple>0:../../devel/p5-Test-Simple
DEPENDS+=	p5-ExtUtils-MakeMaker>0:../../devel/p5-ExtUtils-MakeMaker

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/Data/Dumper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
