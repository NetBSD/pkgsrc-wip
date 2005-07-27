# $NetBSD: Makefile,v 1.3 2005/07/27 19:00:48 kuli0020 Exp $

DISTNAME=		Lingua-Stem-0.81
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/~snowhare/Lingua-Stem/
COMMENT=	Provides word stemming algorithms localized by language

BUILD_DEPENDS=	p5-Lingua-PT-Stemmer>=0:../../textproc/p5-Lingua-PT-Stemmer
DEPENDS+=	p5-Lingua-Stem-Fr>=0.02:../../textproc/p5-Lingua-Stem-Fr
DEPENDS+=	p5-Lingua-Stem-It>=0:../../textproc/p5-Lingua-Stem-It
DEPENDS+=	p5-Lingua-Stem-Ru>=0:../../textproc/p5-Lingua-Stem-Ru
DEPENDS+=	p5-Lingua-Stem-Snowball-Da>=1.01:../../textproc/p5-Lingua-Stem-Snowball-Da
DEPENDS+=	p5-Lingua-Stem-Snowball-No>=0:../../textproc/p5-p5-Lingua-Stem-Snowball-No
DEPENDS+=	p5-Lingua-Stem-Snowball-Se>=1.01:../../textproc/p5-Lingua-Stem-Snowball-Se
DEPENDS+=	p5-Text-German>=0:../../textproc/p5-Text-German

MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

PERL5_PACKLIST= auto/Lingua/Stem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
