# $NetBSD$

VERSION=	0.83
PKGNAME=	neatroff-ubuntu-${VERSION}
CATEGORIES=	fonts

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://design.ubuntu.com/font/
COMMENT=	Neatroff font descriptions for the ubuntu fonts
LICENSE=	ubuntu-font-license

DEPENDS+=	ubuntu-fonts-${VERSION}{,nb*}:../../fonts/ubuntu-fonts
TOOL_DEPENDS+=	neatmkfn-[0-9]*:../../wip/neatmkfn

MKFN=		${PREFIX}/bin/neatmkfn
FONTDIR=	share/fonts/X11/TTF

do-build:
.for f in B BI C L LI M MI R RI
	${MKFN} -b -l -o -t Ubuntu-${f}					\
		-f ${PREFIX}/${FONTDIR}/Ubuntu-${f}.ttf			\
		< ${PREFIX}/${FONTDIR}/Ubuntu-${f}.ttf			\
		> ${WRKDIR}/Ubuntu-${f}
.endfor
.for f in B BI R RI
	${MKFN} -b -l -o -t UbuntuMono-${f}				\
		-f ${PREFIX}/${FONTDIR}/UbuntuMono-${f}.ttf		\
		< ${PREFIX}/${FONTDIR}/UbuntuMono-${f}.ttf		\
		> ${WRKDIR}/UbuntuMono-${f}
.endfor

INSTALLATION_DIRS=	share/neatroff/devutf

do-install:
.for f in B BI C L LI M MI R RI
	${INSTALL_DATA} ${WRKDIR}/Ubuntu-${f}				\
		${DESTDIR}${PREFIX}/share/neatroff/devutf
.endfor
.for f in B BI R RI
	${INSTALL_DATA} ${WRKDIR}/UbuntuMono-${f}			\
		${DESTDIR}${PREFIX}/share/neatroff/devutf
.endfor

.include "../../mk/bsd.pkg.mk"
