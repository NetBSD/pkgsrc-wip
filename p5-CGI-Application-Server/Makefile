# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	CGI-Application-Server-0.063
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/
COMMENT=	Simple HTTP server for developing with CGI::Application

DEPENDS+=	p5-CGI-Application>=4.0:../../www/p5-CGI-Application
DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-HTTP-Server-Simple>=0:../../www/p5-Test-HTTP-Server-Simple
DEPENDS+=	p5-CGI-Application-Plugin-Redirect>=0:../../wip/p5-CGI-Application-Plugin-Redirect
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
DEPENDS+=       p5-HTTP-Server-Simple>=0:../../www/p5-HTTP-Server-Simple
DEPENDS+=       p5-Test-WWW-Mechanize>=0:../../www/p5-Test-WWW-Mechanize
DEPENDS+=       p5-HTTP-Server-Simple-Static>=0:../../www/p5-HTTP-Server-Simple-Static

PERL5_PACKLIST=		auto/CGI/Application/Server/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
