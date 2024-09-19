# $NetBSD: Makefile,v 1.6 2012/10/04 09:13:18 asau Exp $
#

DISTNAME=	AI-NeuralNet-Simple-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AI/}

MAINTAINER=	athaba@users.sourceforge.net
HOMEPAGE=	https://metacpan.org/release/OVID/AI-NeuralNet-Simple-0.11
COMMENT=	Easy to use backprop neural net
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Agent>=0.208:../../devel/p5-Log-Agent
DEPENDS+=	p5-Sub-Uplevel>=0:../../devel/p5-Sub-Uplevel
DEPENDS+=	p5-Test-Exception>=0.15:../../devel/p5-Test-Exception

PERL5_PACKLIST=	auto/AI/NeuralNet/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
