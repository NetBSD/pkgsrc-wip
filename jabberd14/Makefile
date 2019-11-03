# $NetBSD: Makefile,v 1.44 2019/07/30 18:41:58 gdt Exp $

# Upstream's latest release is 1.6.1.1, but this is old and has build
# problems.  Upstream master is better, but upstream is choosing not
# to make a release.  Therefore, package master in wip, and use a
# version number that's higher than 1.6.1.1 and lower than any version
# upstream might choose next.
#
# Because upstream is not publishing a release because of stability
# concerns, this blocks moving this package to pkgsrc proper, as we do
# generally not package non-releases against the wishes of upstreams.
#
# When imported, this will be jabberd14, to avoid confusion with
# jabberd2, and to follow the pattern of all names having versions, if
# there is more than one.
# 
DISTNAME=		jabberd-1.6.1.1.80
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=mawis/}

GITHUB_TAG=		b2b871eaf3f6455d7d37113ce23d6bc59c8da70f
#GITHUB_TAG=		JABBERD14_1_6_1_1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://jabberd.org/
COMMENT=		Instant messaging server
LICENSE=		gnu-gpl-v2

CONFLICTS=		jabberd2-[0-9]*

BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4
TOOL_DEPENDS+=		libtool-base-[0-9]*:../../devel/libtool-base

WRKSRC=			${WRKDIR}/jabberd-${GITHUB_TAG}/jabberd14

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf automake gettext gmake pkg-config
USE_LANGUAGES=		c c++11

.include "options.mk"

BUILD_DEFS+=		JABBERD_PIDDIR JABBERD_SPOOLDIR

PKG_GROUPS=		${JABBERD_GROUP}
PKG_USERS=		${JABBERD_USER}:${JABBERD_GROUP}
PKG_USERS_VARS+=	JABBERD_USER
PKG_GROUPS_VARS+=	JABBERD_GROUP

FILES_SUBST+=		JABBERD_USER=${JABBERD_USER}
FILES_SUBST+=		JABBERD_GROUP=${JABBERD_GROUP}
FILES_SUBST+=		JABBERD_SPOOLDIR=${JABBERD_SPOOLDIR}
FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR}

RCD_SCRIPTS=		jabberd
PKG_SYSCONFSUBDIR=	jabberd
EGDIR=			${PREFIX}/share/examples/jabberd
CONF_FILES=		${EGDIR}/cacerts.pem ${PKG_SYSCONFDIR}/cacerts.pem
CONF_FILES+=		${EGDIR}/jabber.xml ${PKG_SYSCONFDIR}/jabber.xml
INSTALLATION_DIRS+=	${EGDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.am
SUBST_VARS.paths=	EGDIR JABBERD_LOGDIR JABBERD_PIDDIR JABBERD_SPOOLDIR
SUBST_MESSAGE.paths=	Fixing absolute paths.

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

post-install:
	${RM} -f ${DESTDIR}${PKG_SYSCONFBASEDIR}/jabber.xml.dist

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/pth/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
