# $NetBSD: Makefile,v 1.5 2013/04/30 02:29:43 jgoamakf Exp $
#

DISTNAME=	Net-Twitter-Lite-0.12003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Twitter-Lite/
COMMENT=	Perl interface to the Twitter API (lite)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-JSON-Any>=1.21:../../converters/p5-JSON-Any
DEPENDS+=	p5-Net-OAuth>=0.20:../../net/p5-Net-OAuth
DEPENDS+=	p5-URI>=1.40:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/Twitter/Lite/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
