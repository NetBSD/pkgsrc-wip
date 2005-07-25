# $NetBSD: Makefile,v 1.1.1.1 2005/07/25 17:04:39 kuli0020 Exp $

DISTNAME=	Bit-Vector-Minimal-1.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Bit-Vector-Minimal/
COMMENT=	"Object-oriented wrapper around Perl's vec()"

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Bit/Vector/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
