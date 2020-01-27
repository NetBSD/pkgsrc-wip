# $NetBSD$

PKGNAME=	openafs-1.9pre0
GIT_REPO=	git://git.openafs.org/openafs.git
CATEGORIES=	filesystems net sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openafs.org/
COMMENT=	File system for sharing, scalability and transparent data migration
LICENSE=	ipl-1.0 AND mit AND modified-bsd # AND sun-rpc?

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	rx-[0-9]*

.if 0
MAKE_JOBS_SAFE=	no
.else
USE_TOOLS+=	gmake
.endif

GNU_CONFIGURE=		yes
USE_TOOLS+=		lex
USE_TOOLS+=		autoconf aclocal autoheader automake perl
RCD_SCRIPTS+=		bosserver

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-roken=internal

USE_GNU_CONFIGURE_HOST=	no

WRKSRC=		${WRKDIR}/openafs

PLIST_SRC+=		${.CURDIR}/PLIST
OWN_DIRS+=		${PKG_SYSCONFDIR}/openafs
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/openafs/server ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 775
OWN_DIRS_PERMS+=	${VARBASE}/openafs ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 770
OWN_DIRS+=		${VARBASE}/openafs/logs
OWN_DIRS_PERMS+=	${VARBASE}/openafs/db ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}

BUILD_DEFS+=	VARBASE

#
# Rename liblwp.a to libafslwp.a to avoid conflict with the lwp package.
#
pre-configure:
	find ${WRKSRC} -name Makefile.in | while read f; do \
		${SED}	-e 's|liblwp.a|libafslwp.a|g' \
			-e 's|-llwp|-lafslwp|g' < $$f > $$f.tmp && \
		${MV} $$f.tmp $$f; done && \
	cd ${WRKSRC} && ./regen.sh

#.include "../../mk/krb5.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
