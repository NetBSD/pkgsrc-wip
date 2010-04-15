# $NetBSD: Makefile,v 1.4 2010/04/15 07:10:05 athaba Exp $
#

DISTNAME=	AI-Prolog-0.740
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 lang
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AI/}

MAINTAINER=	athaba@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/AI-Prolog
COMMENT=	Pure Perl predicate logic engine
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Clone>=0.15:../../devel/p5-Clone
DEPENDS+=	p5-Exporter-Tidy>=0.06:../../wip/p5-Exporter-Tidy
DEPENDS+=	p5-Hash-AsObject>=0.05:../../wip/p5-Hash-AsObject
DEPENDS+=	p5-Regexp-Common>=2.119:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Term-ReadLine>=1.01:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-Text-Balanced>=1.95:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Text-Quote>=0.03:../../wip/p5-Text-Quote
DEPENDS+=	p5-aliased>=0.11:../../devel/p5-aliased

PKG_DESTDIR_SUPPORT=    user-destdir

PERL5_PACKLIST=	auto/AI/Prolog/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
