# $NetBSD$

DISTNAME=		elixir-1.5.1
PKGREVISION=	1
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
CHECK_INTERPRETER_SKIP+=	bin/mix
CHECK_INTERPRETER_SKIP+=	lib/elixir/bin/mix

USE_TOOLS+=	gmake gsed
BUILD_TARGET= compile

.include "../../mk/bsd.pkg.mk"

# These have to be included after bsd.pkg.mk otherwise elixir will warn the locale is set incorrectly as latin1
MAKE_ENV += LC_CTYPE="en_US.UTF-8"
MAKE_ENV += LC_LANG="en_US.UTF-8"
MAKE_ENV += LC_ALL=""
