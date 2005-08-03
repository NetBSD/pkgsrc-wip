# $NetBSD: Makefile,v 1.1.1.1 2005/08/03 18:31:05 kuli0020 Exp $

DISTNAME=	Plucene-Plugin-Analyzer-SnowballAnalyzer-1.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FA/FABPOT/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Plucene-Plugin-Analyzer-SnowballAnalyzer
COMMENT=	Stemmed analyzer plugin for p5-Plucene search engine

BUILD_DEPENDS=	p5-Lingua-StopWords>=0:../../textproc/p5-Lingua-StopWords
DEPENDS+=	p5-Lingua-Stem-Snowball>=0:../../textproc/p5-Lingua-Stem-Snowball
DEPENDS+=	p5-Plucene>=0:../../textproc/p5-Plucene

PERL5_PACKLIST= auto/Plucene/Plugin/Analyzer/SnowballAnalyzer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
