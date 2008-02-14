# $NetBSD: Makefile,v 1.1.1.1 2008/02/14 13:37:13 smoppy Exp $

DISTNAME=	fdm-1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fdm/}

MANTAINER=	smoppy@gmail.com
HOMEPAGE=	http://fdm.sourceforge.net/
COMMENT=	Mail fetching, filtering and delivering program

NO_CONFIGURE=	yes

##
# Some fix (avoid patches)
##
SUBST_CLASSES+=			fix-makefile
SUBST_STAGE.fix-makefile=	pre-build
SUBST_MESSAGE.fix-makefile=	Fixing Makefile..
SUBST_FILES.fix-makefile=	Makefile
SUBST_SED.fix-makefile=		-e 's/-I-/-iquote/'

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
