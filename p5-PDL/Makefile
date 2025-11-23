# $NetBSD: Makefile,v 1.5 2012/10/04 19:11:57 asau Exp $

DISTNAME=	PDL-2.100
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDL/}

MAINTAINER=	apost@recalcitrant.org
HOMEPAGE=	http://pdl.perl.org/
COMMENT=	PDL turns perl in to a free, array-oriented, numerical language
LICENSE=	${PERL5_LICENSE}

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
DEPENDS+=	p5-Pod-Parser-[0-9]*:../../textproc/p5-Pod-Parser

TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
TEST_DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which

PERL5_PACKLIST=	auto/PDL/.packlist
MAKE_JOBS_SAFE=	no
REPLACE_PERL+=	Perldl2/pdl2
USE_TOOLS+=	perl

# hardcoded version to be corrected
post-install:
#	${RM} -f   ${DESTDIR}/usr/pkg/lib/perl5/vendor_perl/5.42.0/x86_64-netbsd-thread-multi/PDL/pdldoc.db
	${RM} -f ${DESTDIR}/usr/pkg/lib/perl5/vendor_perl/*/*/PDL/pdldoc.db

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
