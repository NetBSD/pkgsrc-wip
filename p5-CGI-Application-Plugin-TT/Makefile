# $NetBSD: Makefile,v 1.1.1.1 2006/02/17 05:47:57 jgoamakf Exp $

DISTNAME=		CGI-Application-Plugin-TT-1.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cpo
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/CGI-Application-Plugin-TT/
COMMENT=		Add Template Toolkit support to CGI::Application

DEPENDS+=		p5-CGI-Application>=4.0:../../www/p5-CGI-Application
DEPENDS+=		p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit
DEPENDS+=		p5-CGI-Application-Plugin-DevPopup>=0:../../wip/p5-CGI-Application-Plugin-DevPopup

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Application/Plugin/TT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
