# $NetBSD: Makefile,v 1.4 2013/04/12 15:18:51 jgoamakf Exp $

DISTNAME=		CGI-Application-Plugin-TT-1.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/release/CGI-Application-Plugin-TT
COMMENT=		Add Template Toolkit support to CGI::Application
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-CGI-Application>=4.0:../../www/p5-CGI-Application
DEPENDS+=		p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit
DEPENDS+=		p5-CGI-Application-Plugin-DevPopup>=0:../../wip/p5-CGI-Application-Plugin-DevPopup

PERL5_PACKLIST=		auto/CGI/Application/Plugin/TT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
