# $NetBSD: Makefile,v 1.1 2015/05/14 08:42:51 makoto Exp $

DISTNAME=	Apache-Gallery-1.0.2-withoutworldwriteables
PKGNAME=	${DISTNAME:C/-without.*//}
CATEGORIES=	graphics www
MASTER_SITES=	https://cpan.metacpan.org/authors/id/L/LE/LEGART/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://apachegallery.dk/
COMMENT=	Perl5/Apache module for handling image directories
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
PERL5_PACKLIST=	auto/Apache/Gallery/.packlist
USE_LANGUAGES=	# none

TEST_ENV+=	MOD_PERL_API_VERSION=2
BUILD_DEFS+=	VARBASE

SUBST_CLASSES+=		var
SUBST_FILES.var+=	t/004_cache_dir.t
SUBST_SED.var+=		-e 's,/var/tmp/Apache-Gallery,${VARBASE}/cache/www,'
SUBST_STAGE.var=	pre-configure

.include "../../lang/perl5/module.mk"
# for make test
# (still asking for Apache::FakeRequest)
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
