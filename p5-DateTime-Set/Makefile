# $NetBSD: Makefile,v 1.2 2004/05/11 07:50:26 cubidou Exp $

DISTNAME=		DateTime-Set-0.16
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/DateTime-Set/
COMMENT=		Perl module for date/time sets and ranges

DEPENDS+=		p5-DateTime>=0.21:../../wip/p5-DateTime
DEPENDS+=		p5-Set-Infinite>=0.57:../../wip/p5-Set-Infinite

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DateTime/Set/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
