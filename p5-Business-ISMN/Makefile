# $NetBSD: Makefile,v 1.1 2012/09/08 16:33:35 genolopolis Exp $
#

DISTNAME=	Business-ISMN-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/B/BD/BDFOY/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/B/BD/BDFOY/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Tie-Cycle>=0:../../wip/p5-Tie-Cycle

PERL5_PACKLIST=	auto/Business/ISMN/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
