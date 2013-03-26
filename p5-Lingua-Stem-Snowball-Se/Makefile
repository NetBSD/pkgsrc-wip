# $NetBSD: Makefile,v 1.5 2013/03/26 02:11:15 jgoamakf Exp $

DISTNAME=		Snowball-Swedish-1.2
PKGNAME=		p5-Lingua-Stem-Snowball-Se-1.2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASKSH/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/dist/Snowball-Swedish/
COMMENT=		Stemmer for Swedish
LICENSE=		${PERL5_LICENSE}

REPLACE_PERL+=		bin/stemmer-no.pl

PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/Se/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
