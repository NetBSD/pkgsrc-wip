# $NetBSD: Makefile,v 1.1.1.1 2004/03/04 15:43:22 roelants Exp $
#

DISTNAME=		Encode-compat-0.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		compat perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Encode.pm emulation layer

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Encode/compat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
