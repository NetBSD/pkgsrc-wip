# $NetBSD: Makefile,v 1.16 2014/10/13 07:11:11 uccwen Exp $

DISTNAME=	MediaWiki-API-0.41
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXOBUZZ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MediaWiki-API/
COMMENT=	Perl interface to the MediaWiki API
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-Encode>=0:../../textproc/p5-Encode
DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=	auto/MediaWiki/API/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
