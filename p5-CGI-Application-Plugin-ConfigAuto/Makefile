# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:28 thomasklausner Exp $

DISTNAME=	CGI-Application-Plugin-ConfigAuto-1.33
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MARKSTOS/
COMMENT=	Easy config file management for CGI::Application

DEPENDS+=	p5-CGI-Application>=4.11:../../www/p5-CGI-Application
DEPENDS+=	p5-Config-Auto>=0:../../devel/p5-Config-Auto

PERL5_PACKLIST=         auto/CGI/Application/Plugin/ConfigAuto/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
