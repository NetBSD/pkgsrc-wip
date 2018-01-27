# $NetBSD: Makefile,v 1.1 2014/11/14 14:35:47 noud4 Exp $

DISTNAME=	Catalyst-Component-InstancePerContext-0.001001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/G/GR/GRODITI/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~groditi/Catalyst-Component-InstancePerContext/
COMMENT=	Return a new instance a component on each request
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.60000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Component/InstancePerContext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
