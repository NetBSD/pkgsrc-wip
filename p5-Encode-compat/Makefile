# $NetBSD: Makefile,v 1.7 2012/10/04 10:45:26 asau Exp $
#

DISTNAME=		Encode-compat-0.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Encode.pm emulation layer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Encode/compat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
