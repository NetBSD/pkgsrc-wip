# $NetBSD: Makefile,v 1.12 2014/06/18 09:45:35 makoto Exp $
# the version number is for pkglint only
DISTNAME=	tamago-anthy-4.0
PKGREVISION=	${_GIT_PKGVERSION:S/.//g}
LICENSE=	gnu-gpl-v2

# See ../../inputmethod/anthy/Makefile.common
ANTHY_VERSION=	9100h

CATEGORIES=	inputmethod
# egg-anthy
MASTER_SITES=	http://www.meadowy.org/~shirai/elips/
# anthy
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE_JP:=anthy/37536/}
MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.meadowy.org/~shirai/
# HOMEPAGE+=    http://www.m17n.org/tamago/
#
DISTFILES+=	egg-anthy.tar.gz
DISTFILES+=	anthy-${ANTHY_VERSION}.tar.gz
COMMENT=	Tamago(Emacs CJK input) + Anthy engine interface

CONFLICTS=	tamago-[0-9]*
MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

USE_TOOLS+=	pax patch
INFO_FILES=	yes

# requires KANA-Kanji conversion engine
DEPENDS+=	anthy-[0-9]*:../../inputmethod/anthy

GIT_REPOSITORIES=	master
GIT_MODULE.master=	egg
GIT_REPO.master=	git://git.debian.org/git/pkg-anthy/egg.git
GIT_DEEP_CLONE.master=	yes # defined

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/egg

.include "../../editors/emacs/modules.mk"

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}

# This is cvs-package version and DISTFILES may not be automatically read, so:
post-patch:
	set -e;					\
	(cd ${WRKDIR}; pwd;			\
	for i in ${DISTFILES} ; do		\
	${ECHO}  ${DISTDIR}/$${i};		\
	${PAX}	-r -z -f ${DISTDIR}/$${i};	\
	done;)

# overwrite two files from egg-anthy
pre-configure:
	cp -p ${WRKDIR}/egg-anthy/anthy.el	${WRKSRC}/egg
	cp -p ${WRKDIR}/egg-anthy/anthyipc.el	${WRKSRC}/egg

# Take care anthy part, it needs some 'make' there
post-build:
	set -e;	\
	cd ${WRKDIR}/anthy-${ANTHY_VERSION}/src-util;	\
	sh ../configure;	\
	${MAKE} elc-stamp

do-install:
# Original egg install (copied part of mk/install/install.mk)
	set -e; cd ${WRKSRC}; 					\
	${SETENV} ${INSTALL_ENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}	\
			install
# Install anthy-elisp
#  (hide after egg/egg that's why egg/f-anthy instead of just egg/anthy)
	${INSTALL_DATA_DIR}	${DESTDIR}${EMACS_LISPPREFIX}/egg/f-anthy
	${INSTALL_DATA} ${WRKDIR}/anthy-${ANTHY_VERSION}/src-util/*.el	\
				${DESTDIR}${EMACS_LISPPREFIX}/egg/f-anthy
	${INSTALL_DATA} ${WRKDIR}/anthy-${ANTHY_VERSION}/src-util/*.elc	\
				${DESTDIR}${EMACS_LISPPREFIX}/egg/f-anthy
# install misc stuff of egg-anthy
	${INSTALL_DATA_DIR}				${DESTDIR}/${PREFIX}/share/anthy
	${INSTALL_DATA} ${WRKDIR}/egg-anthy/*.readme	${DESTDIR}/${PREFIX}/share/anthy
	${INSTALL_DATA} ${WRKDIR}/egg-anthy/typetab-*	${DESTDIR}/${PREFIX}/share/anthy

PLIST_VARS+=	jisx0213

.if ${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} >= 21
PLIST.jisx0213=		yes
.endif

.include "../../wip/mk/git-package.mk"
# http://mail-index.netbsd.org/pkgsrc-wip-discuss/2014/01/20/msg002556.html
# By unknown reason, tamago repository does not accept --depth=1, see TODO

.include "../../mk/bsd.pkg.mk"
