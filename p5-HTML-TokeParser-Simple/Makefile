# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 17:58:09 kuli0020 Exp $

DISTNAME=	HTML-TokeParser-Simple-3.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/HTML-TokeParser-Simple/
COMMENT=	Subclass of HTML::TokeParser with easy-to-remember method calls

DEPENDS+=	p5-HTML-Parser>=3.25:../../www/p5-HTML-Parser
DEPENDS+=	p5-Sub-Override>=0:../../wip/p5-Sub-Override
BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/HTML/TokeParser/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
