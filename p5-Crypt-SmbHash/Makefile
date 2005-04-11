# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:37 tvierling Exp $
#

DISTNAME=		Crypt-SmbHash-0.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5csm
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-SmbHash/
COMMENT=		Perl5 module for generating LM/NT hashes

DEPENDS+=		p5-Digest-MD4>=1.3:../../security/p5-Digest-MD4

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/SmbHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
