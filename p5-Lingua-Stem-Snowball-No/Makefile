# $NetBSD: Makefile,v 1.1.1.1 2005/07/18 21:37:39 kuli0020 Exp $

DISTNAME=		Snowball-Norwegian-1.0
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASKSH/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/~asksh/Snowball-Norwegian-1.0/No.pm
COMMENT=		Stemmer for Norwegian

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Lingua/Stem/Snowball/No/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
