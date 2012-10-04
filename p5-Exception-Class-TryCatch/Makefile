# $NetBSD: Makefile,v 1.2 2012/10/04 10:45:27 asau Exp $
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

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Exception/Class/TryCatch/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
