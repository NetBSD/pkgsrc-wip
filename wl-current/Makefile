# $NetBSD: Makefile,v 1.1.1.1 2008/11/18 02:11:41 makoto Exp $

DISTNAME=	wl-2.15.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	${_CVS_PKGVERSION:S/.//g}

CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	Mail/news management system with IMAP4rev1 support for Emacs
WRKSRC=		${WRKDIR}/wanderlust
USE_TOOLS=	patch
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	all info
INSTALL_TARGET=	install install-info
MAKE_FLAGS+=	INFODIR=${DESTDIR:Q}${EMACS_INFOPREFIX:Q}
MAKE_FLAGS+=	LISPDIR=${DESTDIR:Q}${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR:Q}
MAKE_FLAGS+=	PIXMAPDIR=${DESTDIR:Q}${PREFIX:Q}/share/wl
INFO_FILES=	# PLIST

DOCDIR=			${PREFIX}/share/doc/wl
EXAMPLESDIR=		${PREFIX}/share/examples/wl
INSTALLATION_DIRS=	${DOCDIR}/en ${DOCDIR}/ja \
			${EXAMPLESDIR}/en ${EXAMPLESDIR}/ja \
			${EMACS_INFOPREFIX}


EMACS_BUILDLINK=	# empty

CVS_ROOT.wanderlust=	:pserver:anonymous:@cvs.m17n.org:/cvs/root
CVS_REPOSITORIES=	wanderlust

	# Change default wl-icon-directory for PIXMAP.
	# Why not just use patch-ab ?  $PREFIX is to be embedded.
pre-build:
	( 	\
	${ECHO} "--- wanderlust/wl/wl-vars.el-orig	2008-02-15 23:10:39.000000000 +0900"	;\
	${ECHO} "+++ wl/wl-vars.el	2008-11-18 09:54:56.000000000 +0900"		;\
	${ECHO} "@@ -172,8 +172,8 @@"								; \
	${ECHO} " "										; \
	${ECHO} " (defcustom wl-icon-directory (if (fboundp 'locate-data-directory)"		; \
	${ECHO} " 				 (locate-data-directory \"wl\")"			; \
	${ECHO} "-			       (let ((icons (expand-file-name \"wl/icons/\""		; \
	${ECHO} "-							      data-directory)))"	; \
	${ECHO} "+			       (let ((icons (expand-file-name \"share/wl/\""	; \
	${ECHO} "+							      \"${PREFIX}\")))"		; \
	${ECHO} " 				 (if (file-directory-p icons)"				; \
	${ECHO} " 				     icons)))"						; \
	${ECHO} "   \"*Directory to load the icon files from, or nil if none.\""			; \
	) | (cd ${WRKSRC}; patch  -p0 )

post-install:
	set -e; \
	for f in BUGS NEWS README; do \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f" ${DESTDIR:Q}${DOCDIR:Q}/en; \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f".ja ${DESTDIR:Q}${DOCDIR:Q}/ja; \
	done
	${INSTALL_DATA} ${WRKSRC:Q}/samples/en/dot.* ${DESTDIR:Q}${EXAMPLESDIR:Q}/en
	${INSTALL_DATA} ${WRKSRC:Q}/samples/ja/dot.* ${DESTDIR:Q}${EXAMPLESDIR:Q}/ja

.include "../../editors/emacs/modules.mk"

.include "options.mk"
.include "../../wip/mk/cvs-package.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/semi/buildlink3.mk"
.include "../../misc/bbdb/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
