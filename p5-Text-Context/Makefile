# $NetBSD: Makefile,v 1.8 2012/10/04 19:11:59 asau Exp $

DISTNAME=	Text-Context-3.7
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	kuli0020@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/module/Text::Context
COMMENT=	Perl module for highlighting search result context snippets
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Text-Context-EitherSide>=1.1:../../textproc/p5-Text-Context-EitherSide
DEPENDS+=	p5-UNIVERSAL-require>=0.03:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_PACKLIST=		auto/Text/Context/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
