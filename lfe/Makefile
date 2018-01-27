# $NetBSD$

GITHUB_PROJECT=	lfe
DISTNAME=	lfe-1.2.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=rvirding/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rvirding/lfe/
COMMENT=	Lisp flavoured erlang
USE_TOOLS+=	gmake
MAKE_ENV+=	MANINSTDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	DESTBINDIR=${DESTDIR}/${PREFIX}/bin/

SUBST_CLASSES+=			lfe
SUBST_STAGE.lfe=		post-patch
SUBST_MESSAGE.lfe=		fixing path to lfe
SUBST_SED.lfe=			-e "s,/usr/bin/env lfe,${PREFIX}/bin/lfe,g"
SUBST_FILES.lfe=		bin/lfec
SUBST_FILES.lfe+=		bin/lfedoc
CHECK_INTERPRETER=		no

NO_CONFIGURE=		yes
BUILD_MAKE_FLAGS=	compile
LICENSE=		apache-2.0

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
