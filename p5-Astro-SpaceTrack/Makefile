# $NetBSD: Makefile,v 1.3 2015/03/11 15:06:47 uccwen Exp $

DISTNAME=	Astro-SpaceTrack-0.099
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Astro/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/Astro-SpaceTrack
COMMENT=	Retrieve orbital data from www.space-track.org
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-URI>=0:../../www/p5-URI
DEPENDS+=		p5-JSON>=0:../../converters/p5-JSON
DEPENDS+=		p5-libwww>=0:../../www/p5-libwww
DEPENDS+=		p5-HTTP-Date>=0:../../www/p5-HTTP-Date
DEPENDS+=		p5-HTTP-Message>=6.03:../../www/p5-HTTP-Message
DEPENDS+=		p5-LWP-Protocol-https>=0:../../www/p5-LWP-Protocol-https

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Astro/SpaceTrack/.packlist

MAKE_PARAMS+=		-n

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
