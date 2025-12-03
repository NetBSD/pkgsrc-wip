# $NetBSD: Makefile,v 1.13 2024/11/30 20:31:07 wiz Exp $

DISTNAME=	helix-25.07.1-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=helix-editor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://helix-editor.com/
COMMENT=	Modal editor inspired by kakoune / neovim
# Additionally, the tree-sitter sources have various licenses.
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}

USE_LANGUAGES=	c c++
USE_TOOLS+=	git pax
MAKE_ENV+=	HELIX_DISABLE_AUTO_GRAMMAR_BUILD=1
# Set per: https://docs.helix-editor.com/building-from-source.html#note-to-packagers
MAKE_ENV+=	HELIX_DEFAULT_RUNTIME=${PREFIX}/share/helix/runtime

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/examples/helix/completion
INSTALLATION_DIRS+=	share/helix/runtime/grammars

.include "cargo-depends.mk"
.include "tree-sitter-depends.mk"

# Fix codeberg / prolog. Extracted dir doesn't contain rev
post-extract:
	${MKDIR} ${WRKSRC}/runtime/grammars/sources
.for name rev url path in ${TS_FILES}
	case "${url}" in \
	"https://codeberg.org/"*) ${LN} -s ${WRKDIR}/${name} ${WRKSRC}/runtime/grammars/sources/${path} ;; \
	*) ${LN} -s ${WRKDIR}/${name}-${rev} ${WRKSRC}/runtime/grammars/sources/${path} ;; \
	esac
.endfor

.include "../../mk/bsd.prefs.mk"

# Cargo manifest since highest precedence: https://docs.helix-editor.com/building-from-source.html#multiple-runtime-directories
post-build:
	${RUN} cd ${WRKSRC} && ${SETENV} CARGO_MANIFEST_DIR=${WRKSRC}/runtime \
		./target/release/hx --grammar build
# not under ${PREFIX}/lib, or else lang/rust/cargo.mk would handle it
.if ${OPSYS} == "Darwin"
	${RUN} cd ${WRKSRC}/runtime/grammars &&				\
	for f in *.so; do						\
		install_name_tool					\
		    -id ${PREFIX}/share/helix/runtime/grammars/$${f}	\
		    $${f};						\
	done
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hx ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/runtime && ${PAX} -rw themes ${DESTDIR}${PREFIX}/share/helix/runtime/
	cd ${WRKSRC}/runtime && ${PAX} -rw queries ${DESTDIR}${PREFIX}/share/helix/runtime/
	cd ${WRKSRC}/contrib && ${PAX} -rw completion ${DESTDIR}${PREFIX}/share/examples/helix/
	${INSTALL_DATA} ${WRKSRC}/runtime/tutor ${DESTDIR}${PREFIX}/share/helix/runtime/tutor
	${INSTALL_LIB} ${WRKSRC}/runtime/grammars/*.so ${DESTDIR}${PREFIX}/share/helix/runtime/grammars/

.PHONY: print-tree-sitter-depends
print-tree-sitter-depends:
	${RUN}${AWK} -f ${FILESDIR}/print-depends.awk ${WRKSRC}/languages.toml

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
