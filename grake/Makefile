# $NetBSD: Makefile,v 1.1.1.1 2010/11/17 10:45:07 ryo-on Exp $
#

DISTNAME=	grake-0.0.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net www
MASTER_SITES=	http://grake.googlecode.com/files/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/grake/
COMMENT=	Tool for scanning webpages for Youtube video links
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Getopt-ArgvFile>=1.11:../../devel/p5-Getopt-ArgvFile
DEPENDS+=	p5-Test-Pod>=1.44:../../devel/p5-Test-Pod
DEPENDS+=	p5-version>=0.77:../../devel/p5-version

PERL5_PACKLIST=	auto/grake/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
