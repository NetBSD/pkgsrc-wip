# $NetBSD: Makefile,v 1.1.1.1 2004/03/04 15:48:02 roelants Exp $
#

DISTNAME=		Locale-Maketext-Lexicon-0.35
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://www.autrijus.org/webl10n/
COMMENT=		Use other catalog formats in Maketext

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/Maketext/Lexicon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
