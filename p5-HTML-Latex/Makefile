# $NetBSD: Makefile,v 1.1.1.1 2003/09/09 21:24:55 jeremy-c-reed Exp $

DISTNAME=		html2latex-1.0
PKGNAME=		p5-HTML-Latex
WRKSRC=			${WRKDIR}/${DISTNAME}/HTML
CATEGORIES=		print www perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=html2latex/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://html2latex.sourceforge.net/
COMMENT=		Perl5 module for converting HTML to LaTeX

DEPENDS+=		p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	 	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Latex/.packlist

# LWP::Simple (called libwwwperl too)
# URI (libwww or Bundle::LWP)
# Image::Magik

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
