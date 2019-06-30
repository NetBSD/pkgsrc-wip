# $NetBSD: Makefile,v 1.5 2013/03/30 20:52:24 jgoamakf Exp $

DISTNAME=	Bit-Vector-Minimal-1.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	https://metacpan.org/release/Bit-Vector-Minimal
COMMENT=	"Object-oriented wrapper around Perl's vec()"
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Bit/Vector/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
