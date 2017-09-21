# $NetBSD: Makefile,v 1.4 2012/10/04 19:12:00 asau Exp $

DISTNAME=	Text-Quote-0.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	athaba@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/Text-Quote
COMMENT=	Quotes strings as required for perl to eval them back correctly

DEPENDS+=	p5-Carp-Assert>=0.13:../../devel/p5-Carp-Assert
DEPENDS+=	p5-IO-Compress-[0-9]*:../../devel/p5-IO-Compress
DEPENDS+=	p5-MIME-Base64>=2.12:../../converters/p5-MIME-Base64

PERL5_PACKLIST=	auto/Text/Quote/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
