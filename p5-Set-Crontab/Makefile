# $NetBSD: Makefile,v 1.2 2004/05/02 22:24:31 blef Exp $

DISTNAME=		Set-Crontab-1.00
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/Set-Crontab/
COMMENT=		Perl module to parse crontab(5)-like lists of integers

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Set/Crontab/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
