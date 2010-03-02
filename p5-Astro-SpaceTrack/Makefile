# $NetBSD: Makefile,v 1.1.1.1 2010/03/02 13:21:03 uccwen Exp $
#

DISTNAME=	Astro-SpaceTrack-0.045
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Astro/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/Astro-SpaceTrack
COMMENT=	Retrieve orbital data from www.space-track.org
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

# TODO: Look for the dependencies in Build.PL.

DEPENDS+=		p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=		p5-Params-Util>=0:../../devel/p5-Params-Util
DEPENDS+=		p5-libwww>=0:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Astro/SpaceTrack/.packlist

MAKE_PARAMS+=		-n

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
