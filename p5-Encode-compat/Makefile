# $NetBSD: Makefile,v 1.8 2012/11/25 11:12:46 roelants Exp $
#

DISTNAME=		Encode-compat-0.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		perl5
HOMEPAGE=		http://search.cpan.org/dist/Encode-compat/
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}
LICENSE=		${PERL5_LICENSE}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Encode.pm emulation layer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Encode/compat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
