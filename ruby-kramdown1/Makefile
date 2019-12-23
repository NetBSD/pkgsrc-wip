# $NetBSD: Makefile,v 1.22 2019/10/05 04:34:02 ryoon Exp $

DISTNAME=		kramdown-1.9.0
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME:S/kramdown/kramdown1/}
CATEGORIES=		textproc

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://kramdown.gettalong.org/
COMMENT=		Pure-Ruby Markdown-superset parser and converter
LICENSE=		mit

RUBYGEM_OPTIONS+=	--format-executable
COMMANDS=		kramdown

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for f in ${COMMANDS}; do \
		${TEST} -f $${f}1${RUBY_SUFFIX} || \
			${MV} $${f}${RUBY_SUFFIX} $${f}1${RUBY_SUFFIX}; \
	done

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
