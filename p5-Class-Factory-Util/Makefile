# $NetBSD: Makefile,v 1.1.1.1 2003/06/17 11:56:04 cubidou Exp $

DISTNAME=		Class-Factory-Util-1.4
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/Class-Factory-Util/
COMMENT=		Perl module to help factory classes

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Factory/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
