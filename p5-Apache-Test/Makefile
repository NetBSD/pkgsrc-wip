# $NetBSD: Makefile,v 1.1.1.1 2003/12/30 06:22:48 amigus Exp $
#

DISTNAME=		Apache-Test-1.07
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5apt
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		adam@migus.org
HOMEPAGE=		http://perl.apache.org/docs/1.0/api/Apache/test.html
COMMENT=		Wrapper for Test.pm to test an Apache server

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Test/.packlist

.include "../../www/ap-perl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
