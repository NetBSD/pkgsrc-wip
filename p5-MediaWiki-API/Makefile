# $NetBSD: Makefile,v 1.3 2008/10/25 15:16:58 leot1990 Exp $
#

DISTNAME=	MediaWiki-API-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXOBUZZ/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/MediaWiki-API/
COMMENT=	Perl interface to the MediaWiki API

PKG_DESTDIR_SUPPORT=	user-destdir

# LWP::UserAgent, JSON::XS, Encode
DEPENDS+=	p5-Encode>=0:../../textproc/p5-Encode
DEPENDS+=	p5-JSON-XS>=0:../../converters/p5-JSON-XS
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=	auto/MediaWiki/API/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
