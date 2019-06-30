# $NetBSD: Makefile,v 1.3 2012/10/04 18:42:20 asau Exp $
#

DISTNAME=	Lingua-Translate-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SAMV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-Translate
COMMENT=	Translate text from one language to another
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Unicode-MapUTF8>=1.09:../../converters/p5-Unicode-MapUTF8
DEPENDS+=	p5-Pod-Constants>=0.15:../../wip/p5-Pod-Constants
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

REPLACE_PERL+=	lib/Lingua/Translate.pm lib/Lingua/Translate/Babelfish.pm
REPLACE_PERL+=	lib/Lingua/Translate/SysTran.pm

PERL5_PACKLIST=	auto/Lingua/Translate/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
