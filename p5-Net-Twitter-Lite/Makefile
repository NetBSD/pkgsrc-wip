# $NetBSD: Makefile,v 1.1.1.1 2009/11/07 21:13:27 leot1990 Exp $
#

DISTNAME=	Net-Twitter-Lite-0.08005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MM/MMIMS/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/Net-Twitter-Lite/
COMMENT=	Perl interface to the Twitter API (lite)
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-JSON-Any>=0:../../converters/p5-JSON-Any
DEPENDS+=	p5-Digest-SHA>=0:../../security/p5-Digest-SHA
DEPENDS+=	p5-Encode>=0:../../textproc/p5-Encode
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Install
PERL5_PACKLIST=		auto/Net/Twitter/Lite/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
