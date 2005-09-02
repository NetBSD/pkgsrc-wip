# $NetBSD: Makefile,v 1.4 2005/09/02 19:49:59 kuli0020 Exp $
#

DISTNAME=		Encode-compat-0.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		compat perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Encode.pm emulation layer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Encode/compat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
