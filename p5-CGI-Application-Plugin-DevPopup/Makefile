# $NetBSD: Makefile,v 1.1.1.1 2006/02/16 11:20:25 jgoamakf Exp $

DISTNAME=		CGI-Application-Plugin-DevPopup-0.94
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/CGI-Application-Plugin-DevPopup/
COMMENT=		Runtime cgiapp info in a popup window

DEPENDS+=		p5-CGI-Application>=4.01:../../www/p5-CGI-Application
DEPENDS+=		p5-Time-HiRes>=1.66:../../time/p5-Time-HiRes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Application/Plugin/DevPopup/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
