# $NetBSD: Makefile,v 1.1.1.1 2009/05/01 23:17:52 ficovh Exp $
#

DISTNAME=	Sub-WrapPackages-1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DC/DCANTRELL/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/D/DC/DCANTRELL/
COMMENT=	Add pre- and post-execution wrappers around all the subroutines


DEPENDS+=	p5-Hook-LexWrap>=0.2:../../devel/p5-Hook-LexWrap

PERL5_PACKLIST=	auto/Sub/WrapPackages/.packlist
USE_LANGUAGES=	# none

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
