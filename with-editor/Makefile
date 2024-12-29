# $NetBSD$

VERSION=	3.4.3
DISTNAME=	with-editor-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=magit/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/with-editor/
COMMENT=
LICENSE=	gnu-gpl-v3

# (still getting) (still getting) makeinfo: unknown option -- css-ref
DEPENDS+=	gtexinfo-[0-9]*:../../devel/gtexinfo
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext

MAKE_ENV=	MANUAL_HTML_ARGS=

NO_CONFIGURE=	yes
USE_LANGUAGES=	#
USE_TOOLS+=	gmake makeinfo
MAKE_JOBS_SAFE=	no

.include "../../editors/emacs/modules.mk"

#INFO_FILES=		yes
#UILD_TARGET=		all
TEST_TARGET=		check
INSTALL_TARGET=		#
INSTALLATION_DIRS=	${PREFIX}/share/emacs/site-lisp/with-editor
AUTO_MKDIRS=		yes

do-install:
	( cd ${WRKSRC} ; \
	${INSTALL} lisp/with-editor-autoloads.el ${DESTDIR}${INSTALLATION_DIRS} ; \
	${INSTALL} lisp/with-editor.el           ${DESTDIR}${INSTALLATION_DIRS} ; \
	${INSTALL} lisp/with-editor.elc          ${DESTDIR}${INSTALLATION_DIRS} ; \
	)

.include "../../wip/dash-el/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"


# /tmp/wip/with-editor/work/with-editor-3.4.3/lisp:
# total 288
# drwxr-xr-x  2 makoto  wheel    240 Dec 30 04:34 .
# drwxr-xr-x  5 makoto  wheel    576 Dec 30 04:34 ..
# -rw-r--r--  1 makoto  wheel   1166 Dec  1 23:19 Makefile
# -rw-r--r--  1 makoto  wheel   4137 Dec 30 04:34 with-editor-autoloads.el
# -rw-r--r--  1 makoto  wheel  43284 Dec 30 04:34 with-editor.el
# -rw-r--r--  1 makoto  wheel  43282 Dec  1 23:19 with-editor.el.orig
# -rw-r--r--  1 makoto  wheel  36291 Dec 30 04:34 with-editor.elc
