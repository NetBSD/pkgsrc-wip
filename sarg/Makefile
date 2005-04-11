# $NetBSD: Makefile,v 1.9 2005/04/11 21:15:30 tvierling Exp $

DISTNAME=		sarg-2.0.5
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sarg/}

PATCH_SITES=		http://sarg.sourceforge.net/
PATCHFILES=		freebsd.patch

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://www.sarg-squid.org/
COMMENT=		Squid-Cache proxy server Analysis Report Generator

DIST_SUBDIR=		${DISTNAME}

AUTOCONF_REQD=		2.56
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-bindir=${PREFIX}/sbin			\
			--enable-mandir=${PREFIX}/man/man1		\
			--enable-sysconfdir=${DATADIR}			\
			--enable-htmldir=${SARG_REPORTSDIR}

USE_PKGINSTALL=		yes

PKG_SYSCONFSUBDIR=	sarg
EGDIR=			${PREFIX}/share/examples/sarg
DATADIR=		${PREFIX}/share/sarg

SARG_REPORTSDIR?=	/var/sarg
SG_LOG?=		/var/squidguard/log/squidGuard.log
SQUID_ACCESSLOG?=	/var/squid/logs/access.log

BUILD_DEFS+=		SARG_REPORTSDIR SG_LOG SQUID_ACCESSLOG

PKG_OPTIONS_VAR=	PKG_OPTIONS.sarg
PKG_SUPPORTED_OPTIONS=	gd
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgd)
.  include "../../graphics/gd/buildlink3.mk"
.endif

FILES_SUBST+=		SARG_REPORTSDIR=${SARG_REPORTSDIR}		\
			SG_LOG=${SG_LOG}				\
			SQUID_ACCESSLOG=${SQUID_ACCESSLOG}
SUBST_CLASSES+=		sargconf sargsrc
SUBST_MESSAGE.sargconf=	"[Adjust values in SARG configuration files]"
SUBST_MESSAGE.sargsrc=	"[Adjust values in SARG sources]"
SUBST_STAGE.sargconf=	pre-configure
SUBST_STAGE.sargsrc=	pre-configure
SUBST_FILES.sargconf=	htaccess sarg.1 sarg.conf
SUBST_FILES.sargsrc=	convlog.c splitlog.c log.c usage.c
SUBST_SED.sargconf=	${FILES_SUBST_SED}
SUBST_SED.sargsrc=	${FILES_SUBST_SED}

OWN_DIRS+=		${SARG_REPORTSDIR}

CONF_FILES=		${EGDIR}/sarg.conf ${PKG_SYSCONFDIR}/sarg.conf	\
			${EGDIR}/css.tpl ${PKG_SYSCONFDIR}/css.tpl	\
			${EGDIR}/exclude_codes ${PKG_SYSCONFDIR}/exclude_codes

post-extract:
		@${FIND} ${WRKSRC} -type d -exec ${CHMOD} +x {} \;
		@${RM} ${WRKSRC}/languages/.new

pre-configure:
		cd ${WRKSRC} && ${AUTOCONF}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/sarg ${PREFIX}/sbin
		${INSTALL_MAN} ${WRKSRC}/sarg.1 ${PREFIX}/man/man1
		${INSTALL_DATA_DIR} ${EGDIR}
		${INSTALL_DATA_DIR} ${DATADIR}/fonts
		${INSTALL_DATA_DIR} ${DATADIR}/images
		${INSTALL_DATA_DIR} ${DATADIR}/languages
		${INSTALL_DATA} ${WRKSRC}/sarg.conf ${EGDIR}
		${INSTALL_DATA} ${WRKSRC}/exclude_codes ${EGDIR}
		${INSTALL_DATA} ${WRKSRC}/css.tpl ${EGDIR}
		${INSTALL_DATA} ${WRKSRC}/fonts/Verdana.TTF ${DATADIR}/fonts
		${INSTALL_DATA} ${WRKSRC}/images/* ${DATADIR}/images
		${INSTALL_DATA} ${WRKSRC}/languages/* ${DATADIR}/languages

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
