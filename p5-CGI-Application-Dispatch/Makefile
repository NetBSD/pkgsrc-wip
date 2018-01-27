# $NetBSD: Makefile,v 1.3 2013/05/07 14:11:37 jgoamakf Exp $
#

DISTNAME=	CGI-Application-Dispatch-3.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/dist/CGI-Application-Dispatch/
COMMENT=	Dispatch requests to CGI::Application based objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CGI-Application>=4.01:../../www/p5-CGI-Application
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-HTTP-Exception-[0-9]*:../../wip/p5-HTTP-Exception

BUILD_DEPENDS+=	p5-CGI-PSGI-[0-9]*:../../www/p5-CGI-PSGI
BUILD_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
BUILD_DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Dispatch/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
