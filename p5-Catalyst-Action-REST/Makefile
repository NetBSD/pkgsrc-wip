# $NetBSD: Makefile,v 1.2 2014/11/14 14:29:52 noud4 Exp $

DISTNAME=	Catalyst-Action-REST-1.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FR/FREW/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~frew/Catalyst-Action-REST/
COMMENT=	A RESTful controller
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.60000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-URI-Find-[0-9]*:../../www/p5-URI-Find
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Action/REST/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
