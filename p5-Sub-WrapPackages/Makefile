# $NetBSD: Makefile,v 1.3 2012/10/04 19:11:59 asau Exp $
#

DISTNAME=	Sub-WrapPackages-2.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DC/DCANTRELL/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/dist/Sub-WrapPackages
COMMENT=	Add pre- and post-execution wrappers around all the subroutines
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Hook-LexWrap>=0.2:../../devel/p5-Hook-LexWrap

PERL5_PACKLIST=	auto/Sub/WrapPackages/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
