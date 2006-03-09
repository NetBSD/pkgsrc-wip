# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 20:36:55 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-I18N-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/C/CH/CHANSEN/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-I18N/
COMMENT=	I18N for Catalyst

DEPENDS+=	p5-Catalyst>=2.99:../../wip/p5-Catalyst
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Locale-Maketext-Simple>=0:../../misc/p5-Locale-Maketext-Simple
DEPENDS+=	{perl>=5.8.5,p5-I18N-LangTags-Detect>=0}:../../misc/p5-I18N-LangTags

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Catalyst/Plugin/I18N/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
