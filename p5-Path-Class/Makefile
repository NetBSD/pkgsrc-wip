# $NetBSD: Makefile,v 1.2 2005/09/15 17:22:54 kuli0020 Exp $

DISTNAME=	Path-Class-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWILLIAMS/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/~kwilliams/Path-Class/
COMMENT=	Cross-platform path specification manipulation

DEPENDS+=	p5-PathTools>=0.37:../../wip/p5-PathTools
BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Path/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
