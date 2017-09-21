# $NetBSD: Makefile,v 1.8 2015/06/12 10:49:46 wiz Exp $

DISTNAME=	Term-ReadLine-Perl5-1.43
#KGNAME=	p5-${DISTNAME:C/Perl5/Perl/}
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ReadLine-Perl/
COMMENT=	Perl module providing minimal interface to Readline libraries
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-Lite-[0-9]*:../../devel/p5-Class-Accessor-Lite
DEPENDS+=	p5-Text-VisualWidth-PP-[0-9]*:../../textproc/p5-Text-VisualWidth-PP
DEPENDS+=	p5-Unicode-EastAsianWidth-[0-9]*:../../converters/p5-Unicode-EastAsianWidth
DEPENDS+=	p5-Unicode-EastAsianWidth-Detect-[0-9]*:../../wip/p5-Unicode-EastAsianWidth-Detect
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Term/ReadLine/Perl5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
