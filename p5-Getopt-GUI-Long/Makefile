# $NetBSD: Makefile,v 1.2 2012/06/10 12:07:00 leot1990 Exp $
#

DISTNAME=	Getopt-GUI-Long-0.91
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HARDAKER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Getopt-GUI-Long/
COMMENT=	Wrapper around Getopt::Long
LICENSE=	artistic-2.0 # OR gpl-v2+

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Getopt/GUI/Long/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
