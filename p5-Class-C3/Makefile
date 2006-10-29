# $NetBSD: Makefile,v 1.3 2006/10/29 08:32:50 shattered Exp $

DISTNAME=		Class-C3-0.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Class-C3/
COMMENT=		Pragma to use the C3 method resolution order algortihm
PERL5_REQD+=	5.8.0

BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=		p5-Test-Exception>=0.15:../../devel/p5-Test-Exception
DEPENDS+=		p5-Scalar-List-Utils>=1.10:../../devel/p5-Scalar-List-Utils
DEPENDS+=		p5-Algorithm-C3>=0.01:../../wip/p5-Algorithm-C3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/C3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
