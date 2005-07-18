# $NetBSD: Makefile,v 1.1.1.1 2005/07/18 21:21:12 kuli0020 Exp $

DISTNAME=		Lingua-Stem-Ru-0.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Lingua-Stem-Ru
COMMENT=		Porter's stemming algorithm for Russian (KOI8-R only)

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Lingua/Stem/Ru/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
