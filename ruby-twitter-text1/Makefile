# $NetBSD: Makefile,v 1.7 2019/06/16 16:16:48 tsutsui Exp $

DISTNAME=	twitter-text-1.14.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/twitter-text/twitter-text1/}
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/twitter-text
COMMENT=	Library that provides text handling for Twitter
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-unf-[0-9]*:../../converters/ruby-unf

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
