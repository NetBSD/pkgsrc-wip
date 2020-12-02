# $NetBSD$

DISTNAME=	opendoas-6.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=duncaen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sunil@nimmagadda.net
HOMEPAGE=	https://github.com/duncaen/opendoas
COMMENT=	Execute commands as another user
LICENSE=	isc

CONFLICTS=	doas-[0-9]*

WRKSRC=		${WRKDIR}/OpenDoas-${PKGVERSION_NOREV}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doas.1 doas.conf.5
SUBST_SED.paths=	-e "s,/etc,${PKG_SYSCONFDIR},"

EGDIR=	share/examples/${PKGBASE}

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${EGDIR}

USE_TOOLS=	gmake yacc
MAKE_FILE=	GNUmakefile

BUILDLINK_TRANSFORM+=	rm:-Werror

SPECIAL_PERMS+=		bin/doas ${SETUID_ROOT_PERMS}
NOT_FOR_UNPRIVILEGED=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${EGDIR}

.include "../../mk/bsd.pkg.mk"
