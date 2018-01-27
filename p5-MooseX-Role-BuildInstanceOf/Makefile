# $NetBSD: Makefile,v 1.1 2014/11/15 11:34:21 noud4 Exp $

DISTNAME=	MooseX-Role-BuildInstanceOf-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JJ/JJNAPIORK/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~jjnapiork/MooseX-Role-BuildInstanceOf/
COMMENT=	Less Boilerplate when you need lots of Instances

DEPENDS+=	p5-Moose>0:../../devel/p5-Moose
DEPENDS+=	p5-Scalar-List-Utils>0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-ExtUtils-MakeMaker>0:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=	p5-MooseX-Iterator>0:../../wip/p5-MooseX-Iterator
DEPENDS+=	p5-Perl6-Junction>0:../../devel/p5-Perl6-Junction
DEPENDS+=	p5-MooseX-Types-Path-Class>0:../../devel/p5-MooseX-Types-Path-Class
DEPENDS+=	p5-MooseX-Role-Parameterized>0:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-List-MoreUtils>0:../../devel/p5-List-MoreUtils

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Role/BuildInstanceOf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
