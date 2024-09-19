# $NetBSD: Makefile,v 1.4 2012/09/28 22:07:29 asau Exp $
#

DISTNAME=		ecb-2.40
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecb/}

MAINTAINER=		pho@cielonegro.org
HOMEPAGE=		http://ecb.sourceforge.net/
COMMENT=		Emacs Code Browser
LICENSE=		gnu-gpl-v2

USE_TOOLS=		find gmake makeinfo
INFO_FILES=		yes

MAKE_FLAGS+=		EMACS=${EMACS_BIN}
MAKE_FLAGS+=		CEDET=${EMACS_LISPPREFIX}/${EMACS_PKGNAME_PREFIX}cedet
EMACS_MODULES=		base
#EMACS_BUILDLINK=	yes  # Causes a conflict with Emacs 23's built-in CEDET.

INSTALLATION_DIRS+=	\
	${PKGINFODIR} \
	${EMACS_LISPPREFIX}/${PKGBASE}

# FIXME
do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/info-help/ecb.info* ${DESTDIR}${PREFIX}/${PKGINFODIR}

	cd ${WRKSRC} && \
		${FIND} ecb-images -print | \
		while read i; do \
			if [ -d "$$i" ]; then \
				${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}/$$i; \
			else \
				${INSTALL_DATA} $$i ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}/$$i; \
			fi; \
		done

.include "../../editors/emacs/modules.mk"
.include "../../wip/cedet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
