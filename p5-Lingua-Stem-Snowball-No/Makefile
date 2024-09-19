# $NetBSD: Makefile,v 1.6 2013/03/26 02:15:35 jgoamakf Exp $

DISTNAME=		Snowball-Norwegian-1.2
PKGNAME=		p5-Lingua-Stem-Snowball-No-1.2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASKSH/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		https://metacpan.org/release/Snowball-Norwegian
COMMENT=		Stemmer for Norwegian
LICENSE=		${PERL5_LICENSE}

REPLACE_PERL+=		bin/stemmer-no.pl

PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/No/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
