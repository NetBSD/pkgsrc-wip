# $NetBSD: Makefile,v 1.2 2005/08/05 19:56:10 kuli0020 Exp $

DISTNAME=       Text-Context-3.5
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	kuli0020@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/module/Text::Context
COMMENT=	Perl module for highlighting search result context snippets

DEPENDS+=	p5-Text-Context-EitherSide>=1.1:../../textproc/p5-Text-Context-EitherSide
DEPENDS+=	p5-UNIVERSAL-exports>=0.03:../../devel/p5-UNIVERSAL-exports

PERL5_PACKLIST=		auto/Text/Context/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
