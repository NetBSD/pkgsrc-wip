# $NetBSD: Makefile,v 1.2 2006/01/25 11:35:36 jgoamakf Exp $

DISTNAME=	Test-MockObject-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Test-MockObject/
COMMENT=	Tests remote URLs or local web files
PERL5_REQD+=	5.6.0

BUILD_DEPENDS+=	{perl>=5.8.0,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-UNIVERSAL-can>=1.00:../../wip/p5-UNIVERSAL-can
BUILD_DEPENDS+=	p5-UNIVERSAL-isa>=0.02:../../wip/p5-UNIVERSAL-isa
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn>=0:../../devel/p5-Test-Warn

INSTALL_TARGET=	pure_install

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST= auto/Test/MockObject/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
