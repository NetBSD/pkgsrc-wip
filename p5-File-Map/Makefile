# $NetBSD: Makefile,v 1.5 2014/01/04 14:10:49 uccwen Exp $

DISTNAME=	File-Map-0.65
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/File-Map
COMMENT=	Memory mapping made simple and safe
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XSLoader-[0-9]*:../../devel/p5-XSLoader
DEPENDS+=	p5-Sub-Exporter-Progressive>=0.001005:../../devel/p5-Sub-Exporter-Progressive
DEPENDS+=	p5-PerlIO-Layers-[0-9]*:../../wip/p5-PerlIO-Layers

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=		auto/File/Map/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
