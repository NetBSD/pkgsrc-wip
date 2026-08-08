# $NetBSD$

RUBY_VERSION=	1.8.7
DISTNAME=	ruby-${RUBY_VERSION}-p374
PKGNAME=	${DISTNAME:S/ruby-/ruby18-/:S/-p/pl/}
CATEGORIES=	lang ruby
MASTER_SITES=	https://cache.ruby-lang.org/pub/ruby/1.8/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://cache.ruby-lang.org/pub/ruby/1.8/
COMMENT=	Scripting language for quick and easy object-oriented programming
LICENSE=	gnu-gpl-v2 OR ruby-license

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	yacc

.include "../..//mk/bsd.prefs.mk"

RUBY_SUFX=		18
CONFIGURE_ARGS+=	--program-suffix=${RUBY_SUFX}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--enable-install-doc

.if ${SHLIB_TYPE} == "dylib"
RUBY_DLEXT=	bundle
RUBY_SLEXT=	dylib
.else
RUBY_DLEXT=	so
RUBY_SLEXT=	so
.endif

RUBY_SHLIBVER=		18.7
RUBY_SHLIB_MAJOR=	${RUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1\2/}

RUBY_SHLIB=		${RUBY_SUFX}.${RUBY_SLEXT}.${RUBY_SHLIBVER}
RUBY_SHLIBALIAS=	${RUBY_SUFX}.${RUBY_SLEXT}.${RUBY_SHLIB_MAJOR}
RUBY_STATICLIB=		${RUBY_SUFX}-static.a

PRINT_PLIST_AWK+=	/lib\/libruby${RUBY_STATICLIB}$$/ \
			{ sub(/${RUBY_STATICLIB}/, "$${RUBY_STATICLIB}"); }
PRINT_PLIST_AWK+=	/lib\/libruby${RUBY_SUFX}\.${RUBY_SLEXT}/ \
			{ sub(/${RUBY_SUFX}\.${RUBY_SLEXT}$$/, \
			"$${RUBY_SUFX}.$${RUBY_SLEXT}"); }
PRINT_PLIST_AWK+=	/${RUBY_SHLIBALIAS}$$/ \
			{ sub(/${RUBY_SHLIBALIAS}$$/, "$${RUBY_SHLIBALIAS}"); }
PRINT_PLIST_AWK+=	/${RUBY_SHLIB}$$/ \
			{ sub(/${RUBY_SHLIB}$$/, "$${RUBY_SHLIB}"); }
PRINT_PLIST_AWK+=	/${RUBY_SLEXT}\.${RUBY_SHLIBVER}$$/ \
			{ sub(/${RUBY_SLEXT}\.${RUBY_SHLIBVER}$$/, \
			"$${RUBY_SLEXT}.$${RUBY_SHLIBVER}"); }
PRINT_PLIST_AWK+=	/\.${RUBY_DLEXT}$$/ \
			{ gsub(/${RUBY_DLEXT}$$/, "$${RUBY_DLEXT}") }

PLIST_SUBST+=		RUBY_DLEXT=${RUBY_DLEXT:Q} RUBY_SLEXT=${RUBY_SLEXT:Q}
PLIST_SUBST+=		RUBY_SHLIB=${RUBY_SHLIB:Q}
PLIST_SUBST+=		RUBY_SHLIBALIAS=${RUBY_SHLIBALIAS:Q}
PLIST_SUBST+=		RUBY_STATICLIB=${RUBY_STATICLIB:Q}

PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
