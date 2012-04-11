# $NetBSD: Makefile,v 1.2 2012/04/11 14:22:40 bubuchka Exp $

DISTNAME=	Algorithm-Combinatorics-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Combinatorics/
COMMENT=	Efficient generation of combinatorial sequences
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Algorithm/Combinatorics/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
