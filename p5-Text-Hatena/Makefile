# $NetBSD: Makefile,v 1.1.1.1 2006/02/13 05:38:42 jgoamakf Exp $

DISTNAME=		Text-Hatena-0.10
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Text-Hatena/
COMMENT=		Perl extension for formatting text with Hatena Style

DEPENDS+=		p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser
DEPENDS+=		p5-Class-Data-Inheritable>=0.04:../../devel/p5-Class-Data-Inheritable
DEPENDS+=		p5-Net-Amazon>=0.04:../../wip/p5-Net-Amazon
DEPENDS+=		p5-URI-Title>=1.61:../../wip/p5-URI-Title
DEPENDS+=		p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit
DEPENDS+=		p5-Jcode>=0.88:../../converters/p5-Jcode

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/Hatena/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
