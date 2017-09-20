# $NetBSD: Makefile,v 1.5 2012/10/04 19:11:57 asau Exp $

DISTNAME=	PDL-2.4.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDL/}

MAINTAINER=	apost@recalcitrant.org
HOMEPAGE=	http://pdl.perl.org/
COMMENT=	PDL turns perl in to a free, array-oriented, numerical language

DEPENDS+=	p5-Term-ReadLine-[0-9]*:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter
DEPENDS+=	p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced


PERL5_PACKLIST=		auto/PDL/.packlist

#
# These should work eventually, but are disabled for now.  It looks like
# PDL::FFTW has problems on amd64, at the very least.  Note that PDL-2.4.2
# requires FFTW 2.X, rather than FFTW 3.X.
#
#.include "../../math/fftw2/buildlink3.mk"
#.include "../../math/gsl/buildlink3.mk"

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
