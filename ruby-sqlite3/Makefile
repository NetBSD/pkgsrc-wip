# $NetBSD: Makefile,v 1.2 2005/06/19 14:50:18 obache Exp $
#

DISTNAME=	sqlite3-ruby-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-sqlite3-1.1.0
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/3090/

MAINTAINER=	obata@lins.jp
HOMEPAGE=       http://sqlite-ruby.rubyforge.org/
COMMENT=	SQLite3/Ruby Interface

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

DOCS=	ChangeLog LICENSE README

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/swig13/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/sqlite3/api
.for f in ${DOCS}
	${CP} ${WRKSRC}/${f} ${RUBY_DOCDIR}/sqlite3/
.endfor
	cd ${WRKSRC}/doc && ${PAX} -rw -pp * ${RUBY_DOCDIR}/sqlite3
	cd ${WRKSRC}/api && ${PAX} -rw -pp * ${RUBY_DOCDIR}/sqlite3/api

.include "../../mk/bsd.pkg.mk"
