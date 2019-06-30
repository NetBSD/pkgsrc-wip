# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:30 thomasklausner Exp $

DISTNAME=	Time-Piece-Range-1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	https://metacpan.org/release/Time-Piece-Range
COMMENT=	Time::Piece::Range - deal with a range of Time::Piece objects

DEPENDS+=	p5-Time-Piece>=1.08:../../time/p5-Time-Piece
DEPENDS+=	p5-Date-Range>=1.2:../../wip/p5-Date-Range

PERL5_PACKLIST=		auto/Time/Piece/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
