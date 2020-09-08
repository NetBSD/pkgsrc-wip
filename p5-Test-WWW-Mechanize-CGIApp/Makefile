# $NetBSD: Makefile,v 1.2 2012/10/04 19:11:59 asau Exp $

DISTNAME=	Test-WWW-Mechanize-CGIApp-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/Test::WWW::Mechanize
COMMENT=	Test::WWW::Mechanize for CGI::Application

DEPENDS+=	p5-CGI-Application>=0:../../www/p5-CGI-Application
DEPENDS+=	p5-HTTP-Request-AsCGI>=0:../../www/p5-HTTP-Request-AsCGI
DEPENDS+=	p5-Test-WWW-Mechanize>=1.04:../../www/p5-Test-WWW-Mechanize


PERL5_PACKLIST=	auto/Test/WWW/Mechanize/CGIApp/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
