# $NetBSD$

DISTNAME=	gollum-lib-4.2.10
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gollum/gollum-lib
COMMENT=	Simple, Git-powered wiki with a sweet API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gemojione>=3.2<4:../../wip/ruby-gemojione
DEPENDS+=	${RUBY_PKGPREFIX}-github-markup>=1.6<2:../../wip/ruby-github-markup
DEPENDS+=	${RUBY_PKGPREFIX}-gollum-grit_adapter>=1.0<2:../../wip/ruby-gollum-grit_adapter
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.6.1:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=2.1<3:../../wip/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-sanitize>=2.1.1<2.2:../../wip/ruby-sanitize
DEPENDS+=	${RUBY_PKGPREFIX}-stringex>=2.6<3:../../textproc/ruby-stringex
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-text1>=1.14.7<1.14.8:../../wip/ruby-twitter-text1

DEPENDS+=	${RUBY_PKGPREFIX}-gollum-rugged_adapter-[0-9]*:../../wip/ruby-gollum-rugged_adapter

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
