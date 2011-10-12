# $NetBSD: Makefile,v 1.6 2011/10/12 01:16:43 minskim Exp $

DISTNAME=	emacs-w3m-1.4.50
PKGNAME=	emacs-w3m-1.4.50
PKGREVISION=	${_CVS_PKGVERSION:S/.//g}
CATEGORIES=	www
MASTER_SITES=	#

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://emacs-w3m.namazu.org/
COMMENT=	Emacs frontend for w3m browser

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	makeinfo gzip autoconf
INFO_FILES=	yes

DEPENDS+=	w3m>=0.5.1nb2:../../www/w3m

CVS_REPOSITORIES=	emacs-w3m
CVS_ROOT.emacs-w3m=	:pserver:anonymous:@cvs.namazu.org:/storage/cvsroot

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN:Q}
BUILD_TARGET=
WRKSRC=			${WRKDIR}/emacs-w3m

EVAL_PREFIX=	W3MPREFIX=w3m

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	w3m.el
SUBST_SED.paths+=	-e 's,@W3MPREFIX@,${W3MPREFIX},g'
SUBST_STAGE.paths=	pre-configure

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}

#REPLACE_PERL=		lib-src/grep-changelog

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

PLIST_SRC+=		PLIST

pre-configure:
	(cd ${WRKSRC} ; autoconf)

#.include "../../mk/oss.buildlink3.mk"
.include "../../devel/apel/buildlink3.mk"
.include "../../devel/flim/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
