# $NetBSD: Makefile,v 1.1.1.1 2010/02/23 08:31:53 ficovh Exp $
#

DISTNAME=	App-cpanminus-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MI/MIYAGAWA/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MI/MIYAGAWA/
COMMENT=	App::cpanminus - get, unpack, build and install modules from CPAN
#LICENSE=	license

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Module-Build>=0:../../devel/p5-Module-Build
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww


PERL5_PACKLIST=	auto/App/cpanminus/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
