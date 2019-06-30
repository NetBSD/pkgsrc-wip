# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:28 thomasklausner Exp $

DISTNAME=	Algorithm-Combinatorics-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Combinatorics
COMMENT=	Efficient generation of combinatorial sequences
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Algorithm/Combinatorics/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
