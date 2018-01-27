# $NetBSD: Makefile,v 1.14 2013/05/17 18:00:08 shattered Exp $

DISTNAME=	Plucene-1.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plucene/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Plucene/
COMMENT=	Perl port of the Java Lucene search engine
PERL5_REQD+=	5.6.0

DEPENDS+=	p5-Bit-Vector-Minimal>=1.0:../../wip/p5-Bit-Vector-Minimal
DEPENDS+=	p5-Class-Accessor>=0.18:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Virtual>=0.03:../../devel/p5-Class-Virtual
DEPENDS+=	p5-PathTools>=1.1:../../devel/p5-PathTools
DEPENDS+=	p5-IO-stringy>=2.104:../../devel/p5-IO-stringy
DEPENDS+=	p5-Lingua-Stem>=0.81:../../textproc/p5-Lingua-Stem
DEPENDS+=	p5-Scalar-List-Utils>=1.13:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Memoize>=1.01:../../devel/p5-Memoize
DEPENDS+=	p5-Tie-Array-Sorted>=1.1:../../devel/p5-Tie-Array-Sorted
DEPENDS+=	p5-Time-Piece>=1.08:../../time/p5-Time-Piece
DEPENDS+=	p5-Encode-compat>=0:../../wip/p5-Encode-compat
BUILD_DEPENDS+=	p5-File-Slurp>=2002.1031:../../devel/p5-File-Slurp

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Plucene/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
