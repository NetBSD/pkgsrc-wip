# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:30 thomasklausner Exp $

DISTNAME=		URI-Title-1.901
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/URI-Title/
COMMENT=		Get the titles of things on the web in a sensible way
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Module-Pluggable>=1.2:../../devel/p5-Module-Pluggable
DEPENDS+=		p5-HTML-Parser>=3.45:../../www/p5-HTML-Parser
DEPENDS+=		p5-File-Type>=0.22:../../devel/p5-File-Type
DEPENDS+=		p5-MP3-Info>=1.01:../../audio/p5-MP3-Info
DEPENDS+=		p5-Image-Size>=1.01:../../graphics/p5-Image-Size
DEPENDS+=		p5-libwww>=5.805:../../www/p5-libwww

PERL5_PACKLIST=		auto/URI/Title/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
