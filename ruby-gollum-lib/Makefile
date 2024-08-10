# $NetBSD$

DISTNAME=	gollum-lib-6.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gollum/gollum-lib
COMMENT=	Simple, Git-powered wiki with a sweet API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rouge3>=3.1<4:../../wip/ruby-rouge3
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-loofah>=2.3<3:../../www/ruby-loofah
DEPENDS+=	${RUBY_PKGPREFIX}-github-markup>=4.0<5:../../wip/ruby-github-markup
DEPENDS+=	${RUBY_PKGPREFIX}-gemojione>=4.1<5:../../wip/ruby-gemojione
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-text1>=1.14.7<1.14.8:../../wip/ruby-twitter-text1

DEPENDS+=	${RUBY_PKGPREFIX}-gollum-rugged_adapter>=3.0<4:../../wip/ruby-gollum-rugged_adapter

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
