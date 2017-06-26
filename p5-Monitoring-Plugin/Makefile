# $NetBSD$

DISTNAME=	Monitoring-Plugin-0.39
PKGNAME=    	p5-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NI/NIERLEIN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Monitoring::Plugin
COMMENT=	A family of perl modules for Naemon, Nagios, Icinga or Shinken plugins.
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor>=0.34:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Config-Tiny>=2.23:../../devel/p5-Config-Tiny
DEPENDS+=	p5-Params-Validate>=1.26:../../devel/p5-Params-Validate
DEPENDS+=	p5-Math-Calc-Units>=1.07:../../wip/p5-Math-Calc-Units

PERL5_PACKLIST=	auto/Monitoring/Plugin/.packlist

.include 	"../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
