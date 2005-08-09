# $NetBSD: Makefile,v 1.3 2005/08/09 07:10:48 kristerw Exp $

DISTNAME=	Plucene-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/T/TM/TMTM/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Plucene/
HOMEPAGE=	http://jakarta.apache.org/lucene
COMMENT=	Perl port of the Java Lucene search engine

DEPENDS=	p5-Memoize>=1.01:../../devel/p5-Memoize
DEPENDS+=	p5-Tie-Array-Sorted>=1.1:../../wip/p5-Tie-Array-Sorted
DEPENDS+=	p5-PathTools>=1.1:../../wip/p5-PathTools
DEPENDS+=	p5-Encode-compat>=0:../../wip/p5-Encode-compat
DEPENDS+=	p5-File-Slurp>=2002.1031:../../devel/p5-File-Slurp
DEPENDS+=	p5-Class-Virtual>=0.03:../../wip/p5-Class-Virtual
DEPENDS+=	p5-Class-Accessor>=0.18:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Time-Piece>=1.08:../../time/p5-Time-Piece
# BUILD_DEPENDS+=	p5-Test-Harness>=2.30:../../devel/p5-Test-Harness
DEPENDS+=	p5-Scalar-List-Utils>=1.13:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Lingua-Stem>=0.81:../../wip/p5-Lingua-Stem
DEPENDS+=	p5-Bit-Vector-Minimal>=1.0:../../wip/p5-Bit-Vector-Minimal
DEPENDS+=	p5-Text-Balanced>=0:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-IO-stringy>=2.104:../../devel/p5-IO-stringy

PERL5_PACKLIST= auto/Plucene/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
