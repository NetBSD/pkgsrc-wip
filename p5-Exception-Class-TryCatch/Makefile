# $NetBSD: Makefile,v 1.1.1.1 2009/01/22 16:55:19 ficovh Exp $
#

DISTNAME=	Exception-Class-TryCatch-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DA/DAGOLDEN/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/D/DA/DAGOLDEN/
COMMENT=	Syntactic try/catch sugar for use with Exception::Class

DEPENDS+=	p5-Exception-Class>=0:../../devel/p5-Exception-Class

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=    user-destdir


PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Exception/Class/TryCatch/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
