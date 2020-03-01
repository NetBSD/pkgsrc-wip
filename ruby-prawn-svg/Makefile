# $NetBSD$

DISTNAME=	prawn-svg-0.30.0
CATEGORIES=	print

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://prawnpdf.org/api-docs/2.0/
COMMENT=	SVG renderer for Prawn Ruby PDF library
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-prawn>=1.3.0:../../print/ruby-prawn
DEPENDS+=	${RUBY_PKGPREFIX}-css-parser>=1.6.0:../../www/ruby-css-parser

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
