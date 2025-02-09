# $NetBSD$

PKGNAME=	wipeout-ttf-20211024
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=NR74W/WipEout-Fonts/blob/master/}
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	2097.ttf
DISTFILES+=	2197%20Block.ttf
DISTFILES+=	2197%20Heavy.ttf
DISTFILES+=	Amalgama.ttf
DISTFILES+=	Assegai%20Rounded.ttf
DISTFILES+=	F500%20Ang-ular.ttf
DISTFILES+=	F5000.ttf
DISTFILES+=	FX300%20Angular.ttf
DISTFILES+=	FX300.ttf
DISTFILES+=	Fusion.ttf
DISTFILES+=	WO3.ttf
DISTFILES+=	X2.ttf
DISTFILES+=	supErphoniX2.ttf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NR74W/WipEout-Fonts
COMMENT=	WipEout TrueType fonts
#LICENSE=	unknown

EXTRACT_ONLY=	# empty

WRKSRC=		${WRKDIR}

do-extract:
.for file in ${DISTFILES}
	${CP} ${_DISTDIR}/${file} "${WRKSRC}/${file:S,%20, ,}"
.endfor

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
