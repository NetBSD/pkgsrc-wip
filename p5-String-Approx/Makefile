# $NetBSD: Makefile,v 1.1.1.1 2003/08/14 21:25:14 tvierling Exp $
#

DISTNAME=		String-Approx-3.20
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://search.cpan.org/dist/String-Approx/
COMMENT=		Approximate (fuzzy) string matching library for Perl

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/String/Approx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
