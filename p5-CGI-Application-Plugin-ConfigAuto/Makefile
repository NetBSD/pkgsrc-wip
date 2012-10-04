# $NetBSD: Makefile,v 1.3 2012/10/04 09:13:23 asau Exp $
#

DISTNAME=	CGI-Application-Plugin-ConfigAuto-1.30
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MARKSTOS/
COMMENT=	Easy config file management for CGI::Application

DEPENDS+=	p5-CGI-Application>=4.11:../../www/p5-CGI-Application
DEPENDS+=	p5-Config-Auto>=0:../../devel/p5-Config-Auto



PKG_INSTALLATION_TYPES=	overwrite pkgviews

# url2pkg-marker (please do not remove this line.)
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
