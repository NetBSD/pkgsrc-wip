# $NetBSD$

DISTNAME=	mruby-2.1.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=mruby/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://mruby.org/
COMMENT=	Lightweight implementation of the Ruby language
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison pax

DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

REPLACE_RUBY=	minirake

DOCDIR=		share/doc/mruby

INSTALLATION_DIRS+=	bin ${DOCDIR}

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./minirake --verbose

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/include && ${PAX} -wr *  ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/doc/guides/* ${DESTDIR}${PREFIX}/${DOCDIR}

do-test:
	cd ${WRKSRC} && RUBY=${RUBY} ${RUBY} ./minirake test

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
