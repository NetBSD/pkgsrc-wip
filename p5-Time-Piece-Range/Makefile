# $NetBSD: Makefile,v 1.1.1.1 2005/07/29 14:34:44 kuli0020 Exp $

DISTNAME=	Time-Piece-Range-1.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Time-Piece-Range/
COMMENT=	Time::Piece::Range - deal with a range of Time::Piece objects

DEPENDS+=       p5-Time-Piece>=1.08:../../time/p5-Time-Piece
DEPENDS+=       p5-Date-Range>=1.2:../../time/p5-Date-Range

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Time/Piece/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
