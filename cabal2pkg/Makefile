# $NetBSD$

DISTNAME=	cabal2pkg-0.1.1
PKGNAME=	${DISTNAME}
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=depressed-pho/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/depressed-pho/cabal2pkg
COMMENT=	Tool to automate importing/updating Haskell packages in pkgsrc
LICENSE=	unlicense

# cabal2pkg should not depend on shared Haskell libraries, because it needs
# to be usable even while the tree of Haskell packages in pkgsrc is broken,
# i.e. while we are updating the tree.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	no

# cabal2pkg needs to invoke ${MAKE} at runtime.
ALL_ENV+=	MAKE=${MAKE:Q}

INSTALLATION_DIRS+=	${PKGMANDIR}/man8
post-install:
	${INSTALL_MAN} "${WRKSRC}/doc/cabal2pkg.8" "${DESTDIR}${PREFIX}/${PKGMANDIR}/man8"

.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../textproc/hs-diff3/buildlink3.mk"
.include "../../devel/hs-either/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../textproc/hs-haddock-library/buildlink3.mk"
.include "../../www/hs-http-conduit/buildlink3.mk"
.include "../../www/hs-http-media/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-microlens-platform/buildlink3.mk"
.include "../../devel/hs-mono-traversable/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../devel/hs-ordered-containers/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../textproc/hs-prettyprinter-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-pretty-show/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../archivers/hs-tar-conduit/buildlink3.mk"
.include "../../sysutils/hs-typed-process/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
