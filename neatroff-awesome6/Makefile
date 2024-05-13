# $NetBSD$

.include "../../wip/awesome6-ttf/version.mk"

PKGNAME=	neatroff-awesome6-${FA_VERSION}
CATEGORIES=	fonts

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://fontawesome.com/
COMMENT=	Neatroff font descriptions for the awesome6 fonts
LICENSE=	ofl-v1.1

DEPENDS+=	awesome6-ttf-${FA_VERSION}{,nb*}:../../wip/awesome6-ttf
TOOL_DEPENDS+=	neatmkfn-[0-9]*:../../wip/neatmkfn

MKFN=		${PREFIX}/bin/neatmkfn
FONTDIR=	share/fonts/X11/TTF

do-build:
.for f in fa6-regular-400 fa6-solid-900 fa6-brands-400
	${MKFN} -b -l -o -s -t ${f} -f ${PREFIX}/${FONTDIR}/${f}.ttf	\
		< ${PREFIX}/${FONTDIR}/${f}.ttf > ${WRKDIR}/${f}
.endfor

INSTALLATION_DIRS=	share/neatroff/devutf

do-install:
.for f in fa6-regular-400 fa6-solid-900 fa6-brands-400
	${INSTALL_DATA} ${WRKDIR}/${f}					\
		${DESTDIR}${PREFIX}/share/neatroff/devutf
.endfor

.include "../../mk/bsd.pkg.mk"
