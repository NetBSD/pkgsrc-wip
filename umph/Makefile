# $NetBSD: Makefile,v 1.1.1.1 2010/11/17 10:46:37 ryo-on Exp $
#

DISTNAME=	umph-0.1.6
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://umph.googlecode.com/files/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/umph/
COMMENT=	Command line tool for parsing video links from Youtube feeds
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Getopt-ArgvFile>=1.11:../../devel/p5-Getopt-ArgvFile
DEPENDS+=	p5-XML-DOM>=1.44:../../textproc/p5-XML-DOM
DEPENDS+=	p5-version>=0.77:../../devel/p5-version

PERL5_PACKLIST=	auto/umph/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
