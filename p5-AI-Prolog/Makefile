# $NetBSD$

DISTNAME=	AI-Prolog-0.741
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AI/}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://cpan.perl.org/CPAN/modules/by-module/AI/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	p5-Clone>=0.15:../../devel/p5-Clone
DEPENDS+=	p5-Exporter-Tidy>=0.06:../../wip/p5-Exporter-Tidy
DEPENDS+=	p5-Hash-AsObject>=0.05:../../wip/p5-Hash-AsObject
DEPENDS+=	p5-Regexp-Common>=2.119:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Term-ReadLine>=1.01:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-Text-Balanced>=1.95:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Text-Quote>=0.03:../../wip/p5-Text-Quote
DEPENDS+=	p5-aliased>=0.11:../../devel/p5-aliased

PERL5_PACKLIST=	auto/AI/Prolog/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
