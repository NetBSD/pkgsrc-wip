# $NetBSD$
#

DISTNAME=	Config-YAML-1.42
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-YAML/
COMMENT=	Simple configuration automation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-YAML>=0.35:../../textproc/p5-YAML

PERL5_PACKLIST=	auto/Config/YAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
