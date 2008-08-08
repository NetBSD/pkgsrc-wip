# $NetBSD: Makefile,v 1.1.1.1 2008/08/08 10:14:52 athaba Exp $
#

DISTNAME=	Text-Quote-0.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://search.cpan.org/dist/Text-Quote
COMMENT=	Quotes strings as required for perl to eval them back correctly

PKG_DESTDIR_SUPPORT=user-destdir

DEPENDS+=	p5-Carp-Assert>=0.13:../../devel/p5-Carp-Assert
DEPENDS+=	p5-Compress-Zlib>=1.16:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-MIME-Base64>=2.12:../../converters/p5-MIME-Base64

PERL5_PACKLIST=	auto/Text/Quote/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
