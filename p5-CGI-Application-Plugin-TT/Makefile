# $NetBSD: Makefile,v 1.3 2012/10/04 09:13:26 asau Exp $

DISTNAME=		CGI-Application-Plugin-TT-1.03
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

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Application/Plugin/TT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
