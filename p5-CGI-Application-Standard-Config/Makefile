# $NetBSD: Makefile,v 1.1.1.1 2009/05/01 23:19:47 ficovh Exp $
#

DISTNAME=	CGI-Application-Standard-Config-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MARKSTOS/
COMMENT=	Define a standard configuration API for CGI::Application


PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/CGI/Application/Standard/Config/.packlist
USE_LANGUAGES=		# none

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
