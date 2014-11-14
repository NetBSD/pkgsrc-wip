# $NetBSD: Makefile,v 1.1 2014/11/14 09:42:17 noud4 Exp $

DISTNAME=	Catalyst-View-JSON-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~miyagawa/Catalyst-View-JSON/
COMMENT=	JSON view for your data
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.60000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-JSON-Any-[0-9]*:../../converters/p5-JSON-Any

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
