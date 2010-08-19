# $NetBSD: Makefile,v 1.2 2010/08/19 15:46:10 makoto Exp $
# the version number is for pkglint only
DISTNAME=	tamago-anthy-4.0

PKGREVISION=	${_CVS_PKGVERSION:S/.//g}
# See ../../inputmethod/anthy/Makefile.common
ANTHY_VERSION=	9100h

CATEGORIES=	inputmethod
# anthy
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE_JP:=anthy/37536/}
# egg-anthy
MASTER_SITES+=	http://www.meadowy.org/~shirai/elips/

MAINTAINER=	makoto@ki.nu
HOMEPAGE=       http://www.meadowy.org/~shirai/
# HOMEPAGE+=    http://www.m17n.org/tamago/
#
DISTFILES+=	egg-anthy.tar.gz
DISTFILES+=	anthy-${ANTHY_VERSION}.tar.gz

COMMENT=	Tamago(Emacs CJK input) + Anthy engine interface

CONFLICTS=	tamago-[0-9]*
PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=	pax patch
INFO_FILES=	yes

# requires KANA-Kanji conversion engine
DEPENDS+=	anthy:../../inputmethod/anthy

CVS_REPOSITORIES=	tamago
CVS_ROOT.tamago=	:pserver:anonymous:@cvs.m17n.org:/cvs/tamago

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX}
WRKSRC=			${WRKDIR}/tamago

.include "../../editors/emacs/modules.mk"

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}

#BUILD_DEFS+=		VARBASE
#BUILD_DEFS+=		GAMEDATAMODE

# This is cvs-package version and DISTFILES may not be automatically read, so:
post-patch:
	(cd ${WRKDIR}; pwd;			\
	for i in ${DISTFILES} ; do		\
	${ECHO}  ${DISTDIR}/$${i};		\
	${PAX}	-r -z -f ${DISTDIR}/$${i};	\
	done;)
	if [ -r files/egg-anthy.readme.diff ]; then	\
        cat files/egg-anthy.readme.diff | (cd ${WRKDIR}; patch -s -p0 ) \
	fi

# overwrite two files from egg-anthy
pre-configure:
	cp -p ${WRKDIR}/egg-anthy/anthy.el	${WRKSRC}/egg
	cp -p ${WRKDIR}/egg-anthy/anthyipc.el	${WRKSRC}/egg
	cat files/patch-aa | ( cd ${WRKSRC} ; patch -s -p0 )

# take care anthy part needs some make
post-install:
	cd ${WRKDIR}/anthy-${ANTHY_VERSION}/src-util && (../configure) && ${MAKE} elc-stamp

# anthy-elisp (hide after egg/egg that's why egg/f-anthy instead of just egg/anthy)
	${INSTALL_DATA_DIR}	${DESTDIR}${EMACS_LISPPREFIX}/egg/f-anthy
	${INSTALL_DATA} ${WRKDIR}/anthy-${ANTHY_VERSION}/src-util/*.el	\
				${DESTDIR}${EMACS_LISPPREFIX}/egg/f-anthy
	${INSTALL_DATA} ${WRKDIR}/anthy-${ANTHY_VERSION}/src-util/*.elc	\
				${DESTDIR}${EMACS_LISPPREFIX}/egg/f-anthy
# install egg-anthy others
	${INSTALL_DATA_DIR}				${DESTDIR}/${PREFIX}/share/anthy
	${INSTALL_DATA} ${WRKDIR}/egg-anthy/*.readme	${DESTDIR}/${PREFIX}/share/anthy
	${INSTALL_DATA} ${WRKDIR}/egg-anthy/typetab-*	${DESTDIR}/${PREFIX}/share/anthy

PLIST_VARS+=    jisx0213

.if ${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} >= 21
PLIST.jisx0213=        yes
.endif

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
