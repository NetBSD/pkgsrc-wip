# $NetBSD$

DISTNAME=		elixir-1.3.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=elixir-lang/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://elixir-lang.org/
COMMENT=		Functional, meta-programming aware language built on top of Erlang VM
LICENSE=		apache-2.0

GITHUB_TAG=		v${PKGVERSION_NOREV}

BUILD_DEPENDS+=		erlang>=18.0:../../lang/erlang

WRKSRC=			${WRKDIR}/${PKGBASE}-${PKGVERSION_NOREV}

USE_TOOLS+=	gmake gsed

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-extract
SUBST_FILES.fix-paths=	Makefile
SUBST_SED.fix-paths=	-e 's,/share/man/,/man/,g'

do-build:
	cd ${WRKSRC} && ${GMAKE}

.include "../../mk/bsd.pkg.mk"
