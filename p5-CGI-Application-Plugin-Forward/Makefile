# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:28 thomasklausner Exp $
#

DISTNAME=	CGI-Application-Plugin-Forward-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MG/MGRAHAM/
COMMENT=	Pass control from one run mode to another

DEPENDS+=	p5-CGI-Application>=4.01:../../www/p5-CGI-Application
DEPENDS+=	p5-CGI-Application-Plugin-AutoRunmode>=0:../../wip/p5-CGI-Application-Plugin-AutoRunmode
DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Plugin/Forward/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
