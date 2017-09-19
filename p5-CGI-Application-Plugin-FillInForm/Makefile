# $NetBSD: Makefile,v 1.2 2012/10/04 09:13:24 asau Exp $

DISTNAME=	CGI-Application-Plugin-FillInForm-1.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MA/MARKSTOS/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/~markstos/CGI-Application-Plugin-FillInForm/
COMMENT=	Integrate with HTML::FillInForm

# TODO: Look for the dependencies in Build.PL.
DEPENDS+=	p5-CGI-Application>=4.11:../../www/p5-CGI-Application
DEPENDS+=	p5-HTML-FillInForm>=2.0:../../www/p5-HTML-FillInForm

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Plugin/FillInForm/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
