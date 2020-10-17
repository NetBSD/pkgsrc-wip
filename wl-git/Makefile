# $NetBSD: Makefile,v 1.10 2013/04/06 22:17:47 makoto Exp $

DISTNAME=	wl-2.15.9
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	${_GIT_PKGVERSION:S/.//g}

CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/
LICENSE=	gnu-gpl-v2

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	Mail/news management system with IMAP4rev1 support for Emacs
WRKSRC=		${WRKDIR}/wanderlust
USE_TOOLS=	patch

BUILD_TARGET=	all info
INSTALL_TARGET=	install install-info
MAKE_FLAGS+=	INFODIR=${DESTDIR:Q}${EMACS_INFOPREFIX:Q}
MAKE_FLAGS+=	LISPDIR=${DESTDIR:Q}${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR:Q}
MAKE_FLAGS+=	PIXMAPDIR=${DESTDIR:Q}${PREFIX:Q}/share/wl
INFO_FILES=	YES

	# Change default wl-icon-directory for PIXMAP.
	# Why not just use patch-ab ?  ${PREFIX} is to be embedded.

SUBST_CLASSES+=			icon_directory
SUBST_STAGE.icon_directory=	pre-configure
SUBST_MESSAGE.icon_directory=	Fixing wl-icon-directory default value (defvar)
SUBST_FILES.icon_directory=	${WRKSRC}/wl/wl-vars.el
SUBST_SED.icon_directory=	-e 's|%%PREFIX%%|${PREFIX}|'

DOCDIR=			${PREFIX}/share/doc/wl
EXAMPLESDIR=		${PREFIX}/share/examples/wl
INSTALLATION_DIRS=	${DOCDIR}/en ${DOCDIR}/ja \
			${EXAMPLESDIR}/en ${EXAMPLESDIR}/ja \
			${EMACS_INFOPREFIX}

EMACS_BUILDLINK=	# empty

GIT_REPOSITORIES=       master
GIT_REPO.master=        git://github.com/wanderlust/wanderlust.git
GIT_MODULE.master=      wanderlust
_GIT_FLAGS?=            --depth 1


post-install:
	set -e; \
	for f in BUGS NEWS ; do \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f" ${DESTDIR:Q}${DOCDIR:Q}/en; \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f".ja ${DESTDIR:Q}${DOCDIR:Q}/ja; \
	done
	for f in README ; do \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f".md ${DESTDIR:Q}${DOCDIR:Q}/en; \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f".ja ${DESTDIR:Q}${DOCDIR:Q}/ja; \
	done
	${INSTALL_DATA} ${WRKSRC:Q}/samples/en/dot.* ${DESTDIR:Q}${EXAMPLESDIR:Q}/en
	${INSTALL_DATA} ${WRKSRC:Q}/samples/ja/dot.* ${DESTDIR:Q}${EXAMPLESDIR:Q}/ja

.include "../../wip/emacs-git/modules.mk"

.include "options.mk"
.include "../../wip/mk/git-package.mk"

.include "../../wip/apel-git/buildlink3.mk"
.include "../../devel/semi/buildlink3.mk"
.include "../../misc/bbdb/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
