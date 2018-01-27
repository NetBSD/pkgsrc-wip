# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:28 thomasklausner Exp $

DISTNAME=	CGI-Application-Plugin-ErrorPage-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MARKSTOS/
COMMENT=	Simple error page plugin for CGI::Application

DEPENDS+=	p5-CGI-Application>=4.01:../../www/p5-CGI-Application
DEPENDS+=	p5-Params-Validate>0:../../devel/p5-Params-Validate
DEPENDS+=	p5-Module-Build>0:../../devel/p5-Module-Build

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Plugin/ErrorPage/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
