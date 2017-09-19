# $NetBSD: Makefile,v 1.2 2012/10/04 09:13:25 asau Exp $

DISTNAME=	CGI-Application-Plugin-Stream-2.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/P/PU/PURDY/
COMMENT=	CGI::Application Plugin for streaming files

DEPENDS+=	p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application
DEPENDS+=	p5-File-MMagic>0:../../misc/p5-File-MMagic

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Plugin/Stream/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
