# $NetBSD: Makefile,v 1.5 2011/11/18 02:27:46 phonohawk Exp $
#

DISTNAME=	cedet-1.0pre4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cedet.sourceforge.net/
COMMENT=	Collection of Emacs Development Environment Tools
LICENSE=	gnu-gpl-v3

MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX}

USE_TOOLS+=	gmake
INFO_FILES=	yes

MAKE_FLAGS+=	EMACS=${EMACS_BIN}
EMACS_MODULES+=	base
EMACS_VERSIONS_ACCEPTED= \
	emacs20 \
	emacs21 emacs21nox \
	emacs22 emacs22nox \
	xemacs214 xemacs214nox \
	xemacs215 xemacs215nox

PKG_DESTDIR_SUPPORT=	user-destdir

do-build:
	cd ${WRKSRC} \
        && ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
                EMACS=${EMACS_BIN}

INSTALLATION_DIRS+=	bin ${PKGINFODIR} ${EMACS_LISPPREFIX}/cedet/common/icons
.for pkg in cogre common contrib ede eieio semantic semantic/bovine semantic/wisent speedbar
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/cedet/${pkg}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/semantic/semanticdb.sh ${DESTDIR}${PREFIX}/bin

.for pkg in cogre common contrib ede eieio semantic semantic/bovine semantic/wisent speedbar
	${INSTALL_DATA} ${WRKSRC}/${pkg}/Project.ede ${DESTDIR}${EMACS_LISPPREFIX}/cedet/${pkg}
	${INSTALL_DATA} ${WRKSRC}/${pkg}/*.el ${DESTDIR}${EMACS_LISPPREFIX}/cedet/${pkg}
	${INSTALL_DATA} ${WRKSRC}/${pkg}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}/cedet/${pkg}
.endfor

	${INSTALL_DATA} ${WRKSRC}/common/icons/Project.ede ${DESTDIR}${EMACS_LISPPREFIX}/cedet/common/icons
	${INSTALL_DATA} ${WRKSRC}/common/icons/*.xpm ${DESTDIR}${EMACS_LISPPREFIX}/cedet/common/icons

	${INSTALL_DATA} ${WRKSRC}/*/*.info* ${DESTDIR}${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/*/doc/*.info* ${DESTDIR}${PREFIX}/${PKGINFODIR}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
