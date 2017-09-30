# $NetBSD: Makefile,v 1.2 2013/10/04 14:33:23 makoto Exp $

DISTNAME=	apel-10.8.50
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://git.chise.org/elisp/apel/
COMMENT=	Portable Emacs library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

GIT_REPOSITORIES=	master
GIT_REPO.master=	http://git.chise.org/git/elisp/apel.git
GIT_MODULE.master=	apel
#_GIT_FLAGS+=             --quiet --depth 1

WRKSRC=			${WRKDIR}/${PKGBASE}
INFO_FILES=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		gmake makeinfo
NO_CONFIGURE=		yes

TEST_TARGET=		check
DOCDIR?=		${PREFIX}/share/doc

INSTALLATION_DIRS+=	${DOCDIR} \
			${EMACS_LISPPREFIX:C|^${PREFIX}/||}/apel \
			${EMACS_LISPPREFIX:C|^${PREFIX}/||}/emu

PLIST_SRC=	${PKGDIR}/PLIST.${EMACS_FLAVOR}
BUILD_TARGET=	${BUILD_TARGET.${EMACS_FLAVOR}}
INSTALL_TARGET=	${INSTALL_TARGET.${EMACS_FLAVOR}}
MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR:Q}
MAKE_FLAGS+=	LISPDIR=${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	VERSION_SPECIFIC_LISPDIR=${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	${MAKE_FLAGS.${EMACS_FLAVOR}}

# apel is included in xemacs-packages
EMACS_VERSIONS_ACCEPTED=emacs21 emacs21nox emacs20 emacs25 emacs26 emacs27

BUILD_TARGET.emacs=	elc
BUILD_TARGET.xemacs=	package
INSTALL_TARGET.emacs=	install
INSTALL_TARGET.xemacs=	install-package
MAKE_FLAGS.emacs=
MAKE_FLAGS.xemacs=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}

.include "../../wip/emacs-git/modules.mk"

PLIST_VARS+=	emacs23 emacs19
.if empty(EMACS_TYPE:Mxemacs)
.  if !empty(EMACS_TYPE:Memacs2[3-9]*)
PLIST.emacs23=	yes
.  else
PLIST.emacs19=	yes
.  endif
.endif

# Pkgsrc developers should run "install" without this and check if PLIST is
# correct.  Users just need to install files.
do-install: plist
	cd ${WRKSRC};							\
	for subdir in emu apel; do					\
		grep -v '^@' ${PLIST} | grep "/site-lisp/$$subdir/" |	\
		while read file; do					\
			file=$$( basename $$file );			\
			${INSTALL_DATA} $$file				\
			    ${DESTDIR}${EMACS_LISPPREFIX}/$$subdir/$$file; \
		done							\
	done

.include "../../wip/mk/git-package.mk"
_GIT_FLAGS=             --quiet
.include "../../mk/bsd.pkg.mk"
