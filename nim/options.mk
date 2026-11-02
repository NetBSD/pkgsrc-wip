PKG_OPTIONS_VAR=				PKG_OPTIONS.nim
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)

.include "../../lang/nodejs/buildlink3.mk"
USE_LANGUAGES+=	c++
PLIST_SRC+=			PLIST
PLIST_SRC+=			PLIST.doc

post-build:
	# Build docs
	cd ${WRKSRC} && ./koch \
		docs \
		--parallelBuild:${_MAKE_JOBS_N}

post-install:
	# Copy over docs to ${DESTDIR}
	${MKDIR} -p ${DESTDIR}${PREFIX}/share/doc/nim
	cd ${WRKSRC} && ${CP} -r doc/html/* ${DESTDIR}${PREFIX}/share/doc/nim
.endif
