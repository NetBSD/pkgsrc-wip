# $NetBSD$
#

DISTNAME=	UUID-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UUID/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UUID/
COMMENT=	DCE compatible Universally Unique Identifier library for Perl
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Devel-CheckLib>=1.02:../../devel/p5-Devel-CheckLib

PERL5_PACKLIST=	auto/UUID/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
