# $NetBSD: Makefile,v 1.1 2013/03/09 02:59:23 othyro Exp $
#

DISTNAME=	File-Which-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~adamk/File-Which/
COMMENT=	Portable implementation of the `which' utility
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Script>=1.05:../../devel/p5-Test-Script

PERL5_PACKLIST=	auto/File/Which/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
