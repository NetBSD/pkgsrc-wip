# $NetBSD: Makefile,v 1.1.1.1 2005/07/18 21:47:46 kuli0020 Exp $

DISTNAME=		Snowball-Swedish-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/~asksh/Snowball-Swedish-1.01/Se.pm
COMMENT=		Stemmer for Swedish

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Lingua/Stem/Snowball/Se/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
