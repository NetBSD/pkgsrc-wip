# $NetBSD: Makefile,v 1.1.1.1 2004/09/26 05:28:27 marmfield Exp $
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

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/SmbHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
