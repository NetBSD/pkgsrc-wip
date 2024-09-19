# $NetBSD: Makefile,v 1.5 2018/10/31 12:29:44 wen Exp $

DISTNAME=	FFI-Platypus-1.31
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/FFI-Platypus
COMMENT=	Write Perl bindings to non-Perl libraries with FFI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-Alien-FFI-[0-9]*:../../wip/p5-Alien-FFI
DEPENDS+=		p5-FFI-CheckLib-[0-9]*:../../devel/p5-FFI-CheckLib
DEPENDS+=		p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=		p5-Config-AutoConf-[0-9]*:../../devel/p5-Config-AutoConf

USE_LANGUAGES+=		c c++
PERL5_PACKLIST=		auto/FFI/Platypus/.packlist

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
