# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:53 asau Exp $
#

SHORTNAME=		clx
VERSION=		0.7.4
DISTNAME=		${SHORTNAME}-${VERSION}
CATEGORIES=		x11
DISTFILES=		${DISTNAME}.tgz
SITES.${DISTNAME}.tgz=	http://common-lisp.net/~abridgewater/dist/clx/

MAINTAINER=		lomka@gero.in
HOMEPAGE=		http://gitorious.org/clx
COMMENT=		CLX module which is mostly used with SBCL
#LICENSE=		other/multiple

COMMON_LISP_DOCFILES=	README NEWS
#COMMON_LISP_EXAMPLES=	demo

USE_TOOLS+=		makeinfo install-info
INSTALLATION_DIRS+=	${PKGINFODIR}
INFO_FILES=		yes

# Exclude some excess old style construction, which brakes the build. For SBCL 1.0.55 and upper
SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-extract
SUBST_FILES.sysconf=	depdefs.lisp
SUBST_SED.sysconf=	-e "s/\\(+(or .*little-endian.*)\\)/\\1\#-sbcl/"
# .Xauthority parsing is broken on X.Org. Display "number" field gets junk in it. Do not raise
# parse-error exception for preventing your LISP app from crash as temporary fix. Parsing
# function should be fixed/rewritten or moved to native Xlib function via C callout, like it
# done in clisp-new-clx
SUBST_FILES.sysconf+=	display.lisp
SUBST_SED.sysconf+=	-e "s/\\(parse-integer (read-short-length-string stream)\\)\\(.*\\)/\\1 \
					:junk-allowed t\\2/"

post-extract:
# Remove legacy & useless things. Legacy files are defined in clx.asd
.for f in CHANGES README-R5 excl* cmudep.lisp dep-* sock* defsystem.lisp provide.lisp
	rm ${WRKSRC}/${f}
.endfor

post-install:
	cd ${WRKSRC} && ${MAKEINFO} --no-split ./manual/clx.texinfo -o ./clx.info 2>/dev/null && \
		${RM} -rf ./manual/
	${INSTALL_MAN} ${WRKSRC}/clx.info ${DESTDIR}${PREFIX}/${PKGINFODIR}/clx.info

.include "options.mk"
.include "../../wip/mk/cl-package.mk"

PKGNAME=		${LISP_PREFIX}-portable-clx-${VERSION}

.include "../../mk/bsd.pkg.mk"
