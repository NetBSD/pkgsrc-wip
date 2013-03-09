# $NetBSD: Makefile,v 1.1 2013/03/09 03:47:16 othyro Exp $
#

DISTNAME=	Locale-Maketext-Gettext-1.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~imacat/Locale-Maketext-Gettext/
COMMENT=	Joins the gettext and Maketext frameworks
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Locale/Maketext/Gettext/.packlist
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
