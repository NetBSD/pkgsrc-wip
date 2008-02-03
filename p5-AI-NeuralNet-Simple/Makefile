# $NetBSD: Makefile,v 1.1.1.1 2008/02/03 15:38:43 athaba Exp $
#

DISTNAME=	AI-NeuralNet-Simple-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AI/}

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://search.cpan.org/author/OVID/AI-NeuralNet-Simple-0.11/lib/AI/NeuralNet/Simple
COMMENT=	Easy to use backprop neural net

DEPENDS+=	p5-Log-Agent>=0.208:../../devel/p5-Log-Agent
DEPENDS+=	p5-Sub-Uplevel>=0:../../devel/p5-Sub-Uplevel
DEPENDS+=	p5-Test-Exception>=0.15:../../devel/p5-Test-Exception

PERL5_PACKLIST=	auto/AI/NeuralNet/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
