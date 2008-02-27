# $NetBSD: Makefile,v 1.8 2008/02/27 17:50:55 smoppy Exp $

DISTNAME=	fdm-1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fdm/}

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://fdm.sourceforge.net/
COMMENT=	Mail fetching, filtering and delivering program

PKG_DESTDIR_SUPPORT=	user-destdir
NO_CONFIGURE=		yes

# Preferences handling framework
.include "../../mk/bsd.prefs.mk"

# Unprivileged owner/group
# NOTE: this statement has been put here (and this way) in order
#       to avoid a stupid SUBST block related pkglint(1) warning.
.if defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
UNPRIV_MATCH=		-g bin -o root
UNPRIV_SUBST=		-o ${UNPRIVILEGED_USER} -g ${UNPRIVILEGED_GROUP}
.endif

# Makefile
SUBST_CLASSES=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile..
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e 's/ -I-//'
SUBST_SED.makefile+=	-e "s,/man/,/${PKGMANDIR}/,"
# This may not replace anything
SUBST_SED.makefile+=	-e 's/${UNPRIV_MATCH}/${UNPRIV_SUBST}/g'

# Paths
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Fixing common paths..
SUBST_FILES.paths=	fdm.h fdm.1 fdm.conf.5 MANUAL examples/f-terbeck.conf
SUBST_SED.paths=	-e "s,/etc,${PKG_SYSCONFDIR},"

##
# Options
##
PKG_OPTIONS_VAR=	PKG_OPTIONS.fdm
PKG_SUPPORTED_OPTIONS=	pcre
PKG_SUGGESTED_OPTIONS=	pcre

# Options handling framework
.include "../../mk/bsd.options.mk"

# PCRE support
.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
CFLAGS=	-Dpcre
.endif

##
# Installation directories and configuration files
##
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	bin share/examples ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${EGDIR}
CONF_FILES=		${EGDIR}/fdm.conf.sample ${PKG_SYSCONFDIR}/fdm.conf

# Sample configuration files
post-install:
	${INSTALL_DATA} ${FILESDIR}/fdm.conf ${DESTDIR}${EGDIR}/fdm.conf.sample
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${EGDIR}

.include "../../databases/tdb/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
