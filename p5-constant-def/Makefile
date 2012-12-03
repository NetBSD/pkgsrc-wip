# $NetBSD: Makefile,v 1.1 2012/12/03 19:17:57 othyro Exp $
#

DISTNAME=	constant-def-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MO/MONS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mons/constant-def-0.01/lib/constant/def.pm
COMMENT=	Perl pragma to declare previously undeclared constants
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Simple>=0.98:../../devel/p5-Test-Simple
DEPENDS+=	p5-constant>=1.05:../../devel/p5-constant
DEPENDS+=	p5-ex-lib>=0.03:../../devel/p5-ex-lib

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
