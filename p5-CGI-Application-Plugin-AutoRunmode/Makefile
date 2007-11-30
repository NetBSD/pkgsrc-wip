# $NetBSD: Makefile,v 1.1.1.1 2007/11/30 23:42:17 uhabel Exp $

DISTNAME=		CGI-Application-Plugin-AutoRunmode-0.15
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Application-Plugin-AutoRunmode/
COMMENT=		CGI::App plugin to automatically register runmodes

DEPENDS+=		p5-CGI-Application>=4.01:../../www/p5-CGI-Application

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Application/Plugin/AutoRunmode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
