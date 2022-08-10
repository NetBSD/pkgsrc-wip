# $NetBSD$

DISTNAME=	apple-codesign-0.17.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=indygreg/}
GITHUB_PROJECT=	PyOxidizer
GITHUB_TAG=	apple-codesign/${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gregoryszorc.com/docs/apple-codesign/${PKGVERSION_NOREV}/
COMMENT=	Code signing for Apple platforms
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/PyOxidizer-apple-codesign-${PKGVERSION_NOREV}/apple-codesign

do-install:
	cd ${WRKSRC} && cargo install --path . --root ${DESTDIR}${PREFIX}
	${RM} ${DESTDIR}${PREFIX}/.crates.toml
	${RM} ${DESTDIR}${PREFIX}/.crates2.json

.include "cargo-depends.mk"

#.include "../../lang/python/egg.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
