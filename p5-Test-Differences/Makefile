# $NetBSD: Makefile,v 1.1.1.1 2005/08/01 19:38:52 kuli0020 Exp $

DISTNAME=	Test-Differences-0.47
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Test-Differences/
COMMENT=	Test::Differences - Test strings and data structures for differences

BUILD_DEPENDS=	p5-Text-Diff>=0.00:../../textproc/p5-Text-Diff
DEPENDS+=	p5-Test-Simple>=0.00:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Test/Differences/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
