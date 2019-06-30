# $NetBSD: Makefile,v 1.3 2012/10/04 09:13:33 asau Exp $
#

DISTNAME=		Crypt-Serpent-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		athaba@users.sourceforge.net
HOMEPAGE=		https://metacpan.org/release/Crypt-Serpent
COMMENT=		Serpent block cipher encryption module for perl
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Crypt/Serpent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
