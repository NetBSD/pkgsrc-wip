# $NetBSD: Makefile,v 1.1.1.1 2009/01/22 15:48:07 ficovh Exp $
#

DISTNAME=	CGI-Application-Dispatch-2.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MARKSTOS/
COMMENT=	Dispatch requests to CGI::Application based objects

DEPENDS+=       p5-CGI-Application>=4.01:../../www/p5-CGI-Application
DEPENDS+=       p5-Exception-Class>=0:../../devel/p5-Exception-Class
DEPENDS+=       p5-Exception-Class-TryCatch>=0:../../wip/p5-Exception-Class-TryCatch


# TODO: Look for the dependencies in Build.PL.

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Dispatch/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
