# $NetBSD: Makefile,v 1.9 2014/10/09 14:06:29 thomasklausner Exp $
#

DISTNAME=		Encode-compat-0.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		perl5
HOMEPAGE=		https://metacpan.org/release/Encode-compat
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}
LICENSE=		${PERL5_LICENSE}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Encode.pm emulation layer

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Encode/compat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
