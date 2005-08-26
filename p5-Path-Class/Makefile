# $NetBSD: Makefile,v 1.1.1.1 2005/08/26 17:28:19 kuli0020 Exp $

DISTNAME=	Path-Class-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Path/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/~kwilliams/Path-Class/
COMMENT=	Cross-platform path specification manipulation

DEPENDS+=	p5-PathTools>=0.37:../../devel/p5-PathTools
BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Path/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
