# $NetBSD: Makefile,v 1.11 2018/08/22 09:43:35 wiz Exp $

DISTNAME=	Alien-FFI-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Alien-Build
COMMENT=	Build and make available libffi
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Alien/FFI/.packlist

BUILD_DEPENDS+=	p5-Test2-Suite>=0:../../devel/p5-Test2-Suite

DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
