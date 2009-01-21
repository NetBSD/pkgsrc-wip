# $NetBSD: Makefile,v 1.1.1.1 2009/01/21 19:27:59 ficovh Exp $
#

DISTNAME=	CGI-Application-Plugin-ErrorPage-1.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MARKSTOS/
COMMENT=	Simple error page plugin for CGI::Application

# TODO: Look for the dependencies in Build.PL.

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Plugin/ErrorPage/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
