# $NetBSD: Makefile,v 1.2 2011/01/20 20:33:08 bubuchka Exp $
#

DISTNAME=	Net-Twitter-Lite-0.10003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/Net-Twitter-Lite/
COMMENT=	Perl interface to the Twitter API (lite)
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-JSON-Any>=1.21:../../converters/p5-JSON-Any
DEPENDS+=	p5-Net-OAuth>=0.20:../../net/p5-Net-OAuth
DEPENDS+=	p5-URI>=1.40:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/Net/Twitter/Lite/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
