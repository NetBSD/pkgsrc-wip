# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	CGI-Application-Plugin-ViewCode-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/CGI::Application::Plugin::ViewCode
COMMENT=	View the source of the running application

DEPENDS+=	p5-Syntax-Highlight-Perl-Improved>=1.01:../../wip/p5-Syntax-Highlight-Perl-Improved
DEPENDS+=	p5-CGI-Application>=4:../../www/p5-CGI-Application
DEPENDS+=	p5-Test-LongString>=0.11:../../devel/p5-Test-LongString
DEPENDS+=	p5-Pod-Xhtml>=1:../../wip/p5-Pod-Xhtml

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Plugin/ViewCode/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
