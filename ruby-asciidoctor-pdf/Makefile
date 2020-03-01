# $NetBSD$

DISTNAME=	asciidoctor-pdf-1.5.2
CATEGORIES=	print

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://asciidoctor.org/
COMMENT=	PDF extension for Asciidoctor
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor>=2.0.0:../../wip/ruby-asciidoctor
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.1.0:../../devel/ruby-concurrent-ruby
DEPENDS+=	${RUBY_PKGPREFIX}-prawn-icon>=2.5.0:../../wip/ruby-prawn-icon
DEPENDS+=	${RUBY_PKGPREFIX}-prawn-svg>=0.30.0:../../wip/ruby-prawn-svg
DEPENDS+=	${RUBY_PKGPREFIX}-prawn-table>=0.2.0:../../wip/ruby-prawn-table
DEPENDS+=	${RUBY_PKGPREFIX}-prawn-templates>=0.1.0:../../wip/ruby-prawn-templates
DEPENDS+=	${RUBY_PKGPREFIX}-prawn>=2.2.0:../../print/ruby-prawn
DEPENDS+=	${RUBY_PKGPREFIX}-safe_yaml>=1.0.0:../../textproc/ruby-safe_yaml
DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.3.0:../../misc/ruby-thread_safe
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.6.0:../../wip/ruby-treetop16
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.5.1:../../fonts/ruby-ttfunk

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
