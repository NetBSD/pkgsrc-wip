# $NetBSD$

DISTNAME=	Regexp-Debugger-0.002005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Regexp-Debugger
COMMENT=	Visually debug regexes in-place
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
#DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Regexp/Debugger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
