# $NetBSD: Makefile,v 1.1.1.1 2010/02/08 11:49:12 uccwen Exp $
#

DISTNAME=	Audio-Scan-0.58
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/Audio-Scan/
COMMENT=	XS parser for MP3, MP4, Ogg Vorbis, etc

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Audio/Scan/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
