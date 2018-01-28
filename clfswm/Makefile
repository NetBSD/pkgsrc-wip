# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:54 asau Exp $
#

DISTNAME=		clfswm-1106-2
PKGNAME=		${DISTNAME:S/-2/.2/}
CATEGORIES=		wm
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		lomka@gero.in
HOMEPAGE=		http://common-lisp.net/project/clfswm/
COMMENT=		A(nother) Common Lisp FullScreen Window Manager
LICENSE=		gnu-gpl-v3

HAS_CONFIGURE=		yes
INSTALL_UNSTRIPPED=	yes
# clisp-core linking set, until CLISP 2.50 release
USE_GNU_READLINE=	yes

## Why CLISP?
# Wide arch support, although no native machine code generation (only byte-code, JIT).

# X11 bindings
BUILD_DEPENDS+=		clisp-new-clx>=2.43:../../x11/clisp-new-clx
CONFIGURE_ARGS=		-l clisp
CONFIGURE_ARGS+=	-d ${WRKSRC}/dump/
CONFIGURE_ARGS+=	--with-clfswm ${WRKSRC}
CONFIGURE_ARGS+=	--with-asdf ${WRKSRC}/contrib

INSTALLATION_DIRS+=	bin share/doc/clfswm share/examples/clfswm

.include "../../mk/bsd.prefs.mk"
post-patch:
.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-patch
SUBST_FILES.sysconf=	src/clfswm-info.lisp
SUBST_SED.sysconf=	-e "/info-on-shell.*\".*CPU.*\"/{N; s/\\n//; s/\\(\".*CPU.*:\".*\"\\).*\\(\"\\)/\\1\
				ps -w -r  -ax -o 'user,pid,start,%cpu,%mem,command'\
				\\2/g;}"
SUBST_SED.sysconf+=	-e "/info-on-shell.*\".*MEMORY.*\"/{N; s/\\n//; s/\\(\".*MEMORY.*:\".*\"\\).*\\(\"\\)/\\1\
				ps -w -m  -ax -o 'user,pid,start,%cpu,%mem,command'\
				\\2/g;}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/clfswm ${DESTDIR}${PREFIX}/bin/clfswm
	cp ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/clfswm
	${INSTALL_DATA} ${WRKSRC}/doc/dot-clfswmrc ${DESTDIR}${PREFIX}/share/examples/clfswm/clfswmrc
.for f in AUTHORS COPYING README TODO ChangeLog
	${INSTALL_MAN} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/clfswm
.endfor

do-build:
	cd ${WRKSRC} && ${SH} ./clfswm -n --rebuild && cp dump/clfswm-*.core src/clfswm

# clisp-core linking set
CONFIGURE_ARGS+=	-o "-K ${WRKSRC}/clisp-core"
.include "../../wip/mk/clisp-temp.mk"

.include "../../mk/bsd.pkg.mk"
