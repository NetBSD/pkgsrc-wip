# $NetBSD: options.mk,v 1.1 2026/11/07 22:43:53 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nim
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# This will build the documentation for nim. Because both post-build and
# post-install are not defined prior to this, we can safely just initialize
# them here. Note that to build the documentation, NodeJS is needed, which
# is quite large.
.if !empty(PKG_OPTIONS:Mdoc)
.include "../../lang/nodejs/buildlink3.mk"

# Pull in the latest commits that are available just like upstream
GITHUB_SUBMODULES+=	nim-lang 	asyncftpclient	0350c36d9545040f1038258d7a815493a6103de0 pkgs/asyncftpclient
GITHUB_SUBMODULES+=	nim-lang 	punycode 	03fa3cf9f37c0fbcbdf400c37d9be7a458660dd6 pkgs/punycode
GITHUB_SUBMODULES+=	nim-lang 	smtp 		cd533a340f170f011b2f548048e7b686444e77de pkgs/smtp
GITHUB_SUBMODULES+=	nim-lang 	db_connector 	29450a2063970712422e1ab857695c12d80112a6 pkgs/db_connector
GITHUB_SUBMODULES+=	nim-lang 	checksums 	f58b22377f26d30a89bfbbf1d8a412e20464557d pkgs/checksums
GITHUB_SUBMODULES+=	nim-lang 	atlas	 	c256259c31842ca3596381eeee9c00ff5810ca4c pkgs/atlas
GITHUB_SUBMODULES+=	nim-lang 	htmlparser 	0325ff0840dc7e46496c09cfcc9a424b5ae6f843 pkgs/htmlparser
GITHUB_SUBMODULES+=	nitely		nim-regex 	b078cd018ffa91bb46acff7751882a156601d47e build/deps/nim-regex
GITHUB_SUBMODULES+=	nitely		nim-unicodedb 	b70aac15a3fdc7647997bd6cd10bccd8b2c00e54 build/deps/nim-unicodedb

USE_LANGUAGES+=	c++
PLIST_SRC+=	PLIST
PLIST_SRC+=	PLIST.doc

post-build:
	# Build docs
	cd ${WRKSRC} && ./koch \
		docs \
		--parallelBuild:${_MAKE_JOBS_N} \
		-d:release \
		--docCmd:skip

INSTALLATION_DIRS+=	share/doc/nim

post-install:
	# Copy over docs to ${DESTDIR}
	cd ${WRKSRC} && ${CP} -r doc/html/* ${DESTDIR}${PREFIX}/share/doc/nim

.endif
