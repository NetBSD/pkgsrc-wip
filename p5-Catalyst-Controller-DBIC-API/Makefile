# $NetBSD: Makefile,v 1.1 2014/11/15 12:07:48 noud4 Exp $

DISTNAME=	Catalyst-Controller-DBIC-API-2.007002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AB/ABRAXXA/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~abraxxa/Catalyst-Controller-DBIC-API/
COMMENT=	Provides a REST interface to DBIx::Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-MakeMaker>0:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=	p5-MooseX-Types-Structured>0:../../devel/p5-MooseX-Types-Structured
DEPENDS+=	p5-CGI-Expand>0:../../wip/p5-CGI-Expand
DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>0:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-Catalyst-Action-REST>0:../../www/p5-Catalyst-Action-REST
DEPENDS+=	p5-Data-Printer>0:../../devel/p5-Data-Printer
DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>0:../../www/p5-Test-WWW-Mechanize-Catalyst
DEPENDS+=	p5-JSON>0:../../converters/p5-JSON
DEPENDS+=	p5-Data-DPath-Validator>0:../../wip/p5-Data-DPath-Validator

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Controller/DBIC/API/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
