# $NetBSD: Makefile,v 1.2 2005/08/09 06:59:39 kristerw Exp $

DISTNAME=	Test-Class-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Test-Class/
COMMENT=	Test::Class - Easily create test classes in an xUnit style

BUILD_DEPENDS=	p5-Test-Builder-Tester>=1.01:../../devel/p5-Test-Builder-Tester
DEPENDS+=	p5-Test-Exception>=0.10:../../devel/p5-Test-Exception
DEPENDS+=	p5-Devel-Symdump>=2.03:../../devel/p5-Devel-Symdump
DEPENDS+=	p5-Test-Differences>=0.43:../../wip/p5-Test-Differences
DEPENDS+=	p5-Test-Simple>=0.44:../../devel/p5-Test-Simple
DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
DEPENDS+=	p5-Class-ISA>=0.32:../../wip/p5-Class-ISA
DEPENDS+=	p5-Attribute-Handlers>=0.77:../../devel/p5-Attribute-Handlers

PERL5_PACKLIST= auto/Test/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
