# $NetBSD: Makefile,v 1.3 2012/10/04 09:13:24 asau Exp $

DISTNAME=	CGI-Application-Plugin-LogDispatch-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/CGI::Application::Plugin::LogDispatch
COMMENT=	Add Log::Dispatch support to CGI::Application

# TODO: Look for the dependencies in Build.PL.

DEPENDS+=	p5-Log-Dispatch>=0.21:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-UNIVERSAL-require>=0:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-Sub-WrapPackages>=0:../../wip/p5-Sub-WrapPackages


PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Plugin/LogDispatch/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
