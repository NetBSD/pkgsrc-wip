# $NetBSD: Makefile,v 1.1.1.1 2010/11/17 10:43:51 ryo-on Exp $
#

DISTNAME=	gcap-0.0.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://gcap.googlecode.com/files/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/gcap/
COMMENT=	Command line tool for retrieving Youtube closed captions
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Getopt-ArgvFile>=1.11:../../devel/p5-Getopt-ArgvFile
DEPENDS+=	p5-XML-DOM>=1.44:../../textproc/p5-XML-DOM
DEPENDS+=	p5-version>=0.77:../../devel/p5-version

PERL5_PACKLIST=	auto/gcap/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
