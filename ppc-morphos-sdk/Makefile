# $NetBSD$

PKGNAME=	ppc-morphos-${DISTNAME}
DISTNAME=	sdk-20191111
CATEGORIES=	cross
MASTER_SITES=	https://morphos-team.net/files/
EXTRACT_SUFX=	.lha

MAINTAINER=	js-pkgsrc@heap.zone
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	SDK for ppc-morphos-gcc
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/morphossdk
USE_TOOLS+=	xzcat gtar
USE_LANGUAGES=	# none

do-build:

do-install:
	${RUN} ${MKDIR} ${DESTDIR}${PREFIX}/gg
	# As per https://bigfoot.morphos-team.net/files/setup-cross-sdk.sh
	${RUN} cd ${WRKSRC} && ${XZCAT} sdk.pack | \
		${GTAR} -C ${DESTDIR}${PREFIX}/gg \
			--wildcards \
			--transform "s,^Development/[Gg][Gg]/,," \
			--exclude "ldscripts" \
			-x \
			"Development/[Gg][Gg]/ppc-morphos" \
			"Development/[Gg][Gg]/include" \
			"Development/[Gg][Gg]/includestd" \
			"Development/[Gg][Gg]/os-include" \
			"Development/[Gg][Gg]/bin/*.pl"

.include "../../mk/bsd.pkg.mk"
