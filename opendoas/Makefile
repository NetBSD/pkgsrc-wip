# $NetBSD$

DISTNAME=	opendoas-6.6.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=duncaen/}
GITHUB_TAG=	b1ae418af40289ea4f40449a819df26ee3bdd399

MAINTAINER=	sunil@nimmagadda.net
HOMEPAGE=	https://github.com/duncaen/opendoas
COMMENT=	Execute commands as another user
LICENSE=	isc

CONFLICTS=	doas-[0-9]*

WRKSRC=		${WRKDIR}/OpenDoas-${GITHUB_TAG}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doas.1 doas.conf.5
SUBST_SED.paths=	-e "s,/etc,${PKG_SYSCONFDIR},"

# Let SPECIAL_PERMS handle permissions/setuid of the binary while
# allowing to build as an unprivileged user.
SUBST_CLASSES+=		install
SUBST_MESSAGE.install=	Let SPECIAL_PERMS handle permissions.
SUBST_STAGE.install=	pre-install
SUBST_FILES.install=	bsd.prog.mk
SUBST_SED.install=	-e "/chown/d"
SUBST_SED.install+=	-e "/chmod/d"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

USE_TOOLS=	gmake yacc
BUILD_TARGET=	default

# Prefer NetBSD's libc version of reallocarray(3)
CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE=1

SPECIAL_PERMS+=	bin/doas ${SETUID_ROOT_PERMS}

NOT_FOR_UNPRIVILEGED=	yes

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
