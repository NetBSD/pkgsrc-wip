# $NetBSD: Makefile,v 1.1.1.1 2009/01/09 06:08:26 ficovh Exp $
#

DISTNAME=	CGI-Application-Plugin-Redirect-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/C/CE/CEESHEK/
COMMENT=	Easy external redirects in CGI::Application

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application

PERL5_PACKLIST=		auto/CGI/Application/Plugin/Redirect/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
