# $NetBSD: Makefile,v 1.1.1.1 2003/06/17 12:43:01 cubidou Exp $

DISTNAME=		DateTime-Set-0.08
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/DateTime-Set/
COMMENT=		Perl module for date/time sets and ranges

DEPENDS+=		p5-DateTime>=0.12:../../wip/p5-DateTime
DEPENDS+=		p5-Set-Infinite>=0.49:../../wip/p5-Set-Infinite

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DateTime/Set/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
