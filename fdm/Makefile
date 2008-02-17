# $NetBSD: Makefile,v 1.2 2008/02/17 15:36:55 smoppy Exp $

DISTNAME=	fdm-1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fdm/}

MAINTAINER=	smoppy@gmail.com
HOMEPAGE=	http://fdm.sourceforge.net/
COMMENT=	Mail fetching, filtering and delivering program

NO_CONFIGURE=	yes

##
# Some fix (avoid patches)
##

# Makefile
SUBST_CLASSES=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing Makefile..
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's/-I-/-iquote/'

# Paths
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Fixing paths..
SUBST_FILES.paths=	fdm.h fdm.1 fdm.conf.5 MANUAL examples/f-terbeck.conf
SUBST_SED.paths=	-e "s,/etc,${PKG_SYSCONFDIR},"

##
# Options
##
PKG_OPTIONS_VAR=                PKG_OPTIONS.fdm
PKG_SUPPORTED_OPTIONS=          pcre
PKG_SUGGESTED_OPTIONS=		pcre

# Options handling framework
.include "../../mk/bsd.options.mk"

# PCRE support
.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
CFLAGS=	-Dpcre
.endif

INSTALLATION_DIRS=	bin share/examples ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
CONF_FILES=		${PKG_SYSCONFDIR}/fdm.conf

# Shared examples directory
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

# Copy the configuration file
CONF_FILES=	${EGDIR}/fdm.conf ${PKG_SYSCONFDIR}/fdm.conf

# Sample configuration files
post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/fdm.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EGDIR}

.include "../../databases/tdb/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
