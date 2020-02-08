# $NetBSD$

PKGNAME=	ppc-morphos-${DISTNAME}
PKGREVISION=	2
DISTNAME=	sdk-20191111
CATEGORIES=	cross
MASTER_SITES=	https://morphos-team.net/files/
EXTRACT_SUFX=	.lha

MAINTAINER=	js-pkgsrc@heap.zone
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	SDK for ppc-morphos-gcc
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

WRKSRC=		${WRKDIR}/morphossdk
USE_TOOLS+=	xzcat gtar gsed
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
	gsed -i 's,/usr/bin/perl,${PERL5},g' \
		${DESTDIR}${PREFIX}/gg/bin/cvinclude.pl \
		${DESTDIR}${PREFIX}/gg/bin/genfd.pl

.include "../../mk/bsd.pkg.mk"
