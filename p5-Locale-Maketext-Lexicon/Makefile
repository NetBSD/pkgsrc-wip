# $NetBSD: Makefile,v 1.3 2004/04/13 19:41:17 roelants Exp $
#

DISTNAME=		Locale-Maketext-Lexicon-0.36
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://www.autrijus.org/webl10n/
COMMENT=		Use other catalog formats in Maketext

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/Maketext/Lexicon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
