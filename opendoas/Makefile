# $NetBSD$

DISTNAME=	OpenDoas-6.6.1
PKGNAME=	${DISTNAME:tl}
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

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

USE_TOOLS=	gmake
BUILD_TARGET=	default

CFLAGS+=	-D_OPENBSD_SOURCE=1
CFLAGS+=	-DDOAS_CONF="\"${PKG_SYSCONFDIR}/doas.conf\""

SPECIAL_PERMS+=	bin/doas ${SETUID_ROOT_PERMS}

NOT_FOR_UNPRIVILEGED=	yes

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
