# $NetBSD: Makefile,v 1.9 2012/09/24 18:26:52 asau Exp $
#

DISTNAME=	cedet-1.0.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=		pho@cielonegro.org
HOMEPAGE=		http://cedet.sourceforge.net/
COMMENT=		Collection of Emacs Development Environment Tools
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		find gmake makeinfo
INFO_FILES=		yes

MAKE_FLAGS+=		EMACS=${EMACS_BIN}
EMACS_MODULES+=		base
EMACS_BUILDLINK=	yes

MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX}

CEDET_DIRS= \
	cogre \
	cogre/templates \
	common \
	common/icons \
	contrib \
	ede \
	ede/templates \
	eieio \
	semantic \
	semantic/bovine \
	semantic/ctags \
	semantic/symref \
	semantic/wisent \
	speedbar \
	srecode \
	srecode/templates

INSTALLATION_DIRS+=	${PKGINFODIR}

.for dir in ${CEDET_DIRS}
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/${PKGBASE}/${dir}
.endfor

do-install:
.for dir in ${CEDET_DIRS}
	${RUN} ${FIND} ${WRKSRC}/${dir} \
		-maxdepth 1 \
		\( \
			-name '*.by'  -o \
			-name '*.ede' -o \
			-name '*.el'  -o \
			-name '*.elc' -o \
			-name '*.srt' -o \
			-name '*.xpm' -o \
			-name '*.wy' \
		\) \
		-exec ${INSTALL_DATA} {} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}/${dir} \;
.endfor
	${RUN} ${FIND} ${WRKSRC} \
		-name '*.info*' \
		-exec ${INSTALL_DATA} {} ${DESTDIR}${PREFIX}/${PKGINFODIR} \;

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
