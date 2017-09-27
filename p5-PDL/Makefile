# $NetBSD: Makefile,v 1.5 2012/10/04 19:11:57 asau Exp $

DISTNAME=	PDL-2.018
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDL/}

MAINTAINER=	apost@recalcitrant.org
HOMEPAGE=	http://pdl.perl.org/
COMMENT=	PDL turns perl in to a free, array-oriented, numerical language

DEPENDS+=	p5-Term-ReadLine-[0-9]*:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter
DEPENDS+=	p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib
# recommended, but not necessary
#DEPENDS+=	p5-Astro-FITS-Header-[0-9]*:../../devel/p5-Astro-FITS-Header
DEPENDS+=	p5-Convert-UU-[0-9]*:../../converters/p5-Convert-UU
DEPENDS+=	p5-File-Map-[0-9]*:../../wip/p5-File-Map
DEPENDS+=	p5-Inline-[0-9]*:../../devel/p5-Inline
DEPENDS+=	p5-Inline-C-[0-9]*:../../devel/p5-Inline-C
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Module-Compile-[0-9]*:../../devel/p5-Module-Compile
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/PDL/.packlist
MAKE_JOBS_SAFE=		no

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
