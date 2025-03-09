# $NetBSD$

DISTNAME=	dmarcaroni-client-0.8alpha2025.02.01
CATEGORIES=	mail
# There are no official releases at the moment.
SITES.${DISTNAME}.tar.gz=	-https://git.disroot.org/lnrs/dmarcaroni-client/archive/78e2cc7ab2c194f697512accd25287c6f38b399f.tar.gz
WRKSRC=		${WRKDIR}/${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.disroot.org/lnrs/dmarcaroni-client
COMMENT=	Free and open source software to do DMARC monitoring
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	elm-lang-[0-9]*:../../lang/elm-lang

do-build:
	cd ${WRKSRC} && elm make src/Main.elm --output="dist/main.js"

INSTALLATION_DIRS+=	share/${PKGBASE}/assets
do-install:
	for f in "${WRKSRC}/dist/"*; do \
		case "$$f" in \
			*.orig) :;; \
			*) \
				${INSTALL_DATA} "$$f" "${DESTDIR}${PREFIX}/share/${PKGBASE}";; \
		esac; \
	done
	for f in "${WRKSRC}/assets/"*; do \
		case "$$f" in \
			*.orig) :;; \
			*) \
				${INSTALL_DATA} "$$f" "${DESTDIR}${PREFIX}/share/${PKGBASE}/assets";; \
		esac; \
	done

.include "../../mk/bsd.pkg.mk"
