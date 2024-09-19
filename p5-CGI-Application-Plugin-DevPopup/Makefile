# $NetBSD: Makefile,v 1.5 2014/10/09 14:06:28 thomasklausner Exp $

DISTNAME=		CGI-Application-Plugin-DevPopup-1.08
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/release/CGI-Application-Plugin-DevPopup
COMMENT=		Runtime cgiapp info in a popup window
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-CGI-Application>=4.01:../../www/p5-CGI-Application
#DEPENDS+=		p5-Time-HiRes>=1.66:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/CGI/Application/Plugin/DevPopup/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
