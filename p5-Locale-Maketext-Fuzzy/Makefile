# $NetBSD: Makefile,v 1.1.1.1 2004/03/04 15:46:05 roelants Exp $
#

DISTNAME=		Locale-Maketext-Fuzzy-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Maketext from already interpolated strings

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/Maketext/Fuzzy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
