# $NetBSD: Makefile,v 1.5 2011/04/14 03:27:16 makoto Exp $
# the version number is for pkglint only
DISTNAME=	tamago-anthy-4.0

PKGREVISION=	${_CVS_PKGVERSION:S/.//g}
# See ../../inputmethod/anthy/Makefile.common
ANTHY_VERSION=	9100h

CATEGORIES=	inputmethod
MASTER_SITES=	http://www.meadowy.org/~shirai/elips/
# anthy
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE_JP:=anthy/37536/}
# egg-anthy


MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.meadowy.org/~shirai/
# HOMEPAGE+=    http://www.m17n.org/tamago/
#
DISTFILES+=	egg-anthy.tar.gz
DISTFILES+=	anthy-${ANTHY_VERSION}.tar.gz
COMMENT=	Tamago(Emacs CJK input) + Anthy engine interface

CONFLICTS=	tamago-[0-9]*
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

USE_TOOLS+=	pax patch
INFO_FILES=	yes

# requires KANA-Kanji conversion engine
DEPENDS+=	anthy:../../inputmethod/anthy

CVS_REPOSITORIES=	tamago
CVS_ROOT.tamago=	:pserver:anonymous:@cvs.m17n.org:/cvs/tamago

GNU_CONFIGURE=	yes
WRKSRC=			${WRKDIR}/tamago

.include "../../editors/emacs/modules.mk"

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}

#BUILD_DEFS+=		VARBASE
#BUILD_DEFS+=		GAMEDATAMODE

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

# Take care anthy part, it needs some make there
post-build:
	set -e;	\
	cd ${WRKDIR}/anthy-${ANTHY_VERSION}/src-util;	\
	sh ../configure;	\
	${MAKE} elc-stamp

do-install:
# Original egg install (copied part of mk/install/install.mk)
	set -e; cd ${WRKDIR}/tamago; 					\
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
# install egg-anthy others
	${INSTALL_DATA_DIR}				${DESTDIR}/${PREFIX}/share/anthy
	${INSTALL_DATA} ${WRKDIR}/egg-anthy/*.readme	${DESTDIR}/${PREFIX}/share/anthy
	${INSTALL_DATA} ${WRKDIR}/egg-anthy/typetab-*	${DESTDIR}/${PREFIX}/share/anthy

PLIST_VARS+=	jisx0213

.if ${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} >= 21
PLIST.jisx0213=		yes
.endif

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
