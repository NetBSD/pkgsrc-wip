# $NetBSD: Makefile,v 1.3 2004/05/14 13:34:11 thomasklausner Exp $

.include "Makefile.common"

PKGNAME=		p5-HTML-Latex-${HTML2LATEX_VERSION}
WRKSRC=			${WRKDIR}/${DISTNAME}/HTML
CATEGORIES=		print www perl5

COMMENT=		Perl5 module for converting HTML to LaTeX

DEPENDS+=		p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	 	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Latex/.packlist

# LWP::Simple (called libwwwperl too)
# URI (libwww or Bundle::LWP)
# Image::Magik

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
