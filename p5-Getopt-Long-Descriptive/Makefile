# $NetBSD: Makefile,v 1.1.1.1 2007/12/24 02:02:24 netcap Exp $
#

DISTNAME=	Getopt-Long-Descriptive-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/H/HD/HDP/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/H/HD/HDP/
COMMENT=	Getopt::Long with usage text

DEPENDS+=	p5-Params-Validate>=0.74:../../devel/p5-Params-Validate

PERL5_PACKLIST=	auto/Getopt/Long/Descriptive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
