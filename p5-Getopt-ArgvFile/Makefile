# $NetBSD: Makefile,v 1.1 2007/02/04 09:00:30 cheusov Exp $
#

DISTNAME=		Getopt-ArgvFile-1.10
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://www.cpan.org/modules/by-module/Getopt/
COMMENT=		Interpolates script options from files into @ARGV or another array

PKG_INSTALLATION_TYPES= overwrite pkgviews
PERL5_PACKLIST=		auto/Getopt/ArgvFile/.packlist

DEPENDS+=		p5-Getopt-Simple-[0-9]*:../../devel/p5-Getopt-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
